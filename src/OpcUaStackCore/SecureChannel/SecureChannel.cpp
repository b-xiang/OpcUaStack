/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)

 */

#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	SecureChannel::SecureChannel(IOService* ioService)
	: TCPConnection(ioService->io_service())
	, state_(S_Init)
	, config_()
	, closeFlag_(false)
	, recvBuffer_()
	, sendBuffer_()
	, slotTimerElement_(SlotTimerElement::construct())
	, timeout_(false)
	, partner_()
	, local_()
	, debug_(false)
	, debugHeader_(false)
	, asyncSend_(false)
	, channelId_(0)
	, securityTokenId_(0)
	, typeId_()
	, messageHeader_()

	, receivedBufferSize_(MessageDefaults::receivedBufferSizeDefault_)
	, sendBufferSize_(MessageDefaults::sendBufferSizeDefault_)
	, maxMessageSize_(MessageDefaults::maxMessageSizeDefault_)
	, maxChunkCount_(MessageDefaults::maxChunkCountDefault_)
	, endpointUrl_()

	, secureChannelTransaction_()
	, secureChannelTransactionList_()

	, sendFirstSegment_(true)
	, recvFirstSegment_(true)
	, sendRequestId_(0)
	, recvRequestId_(0)
	, sendSequenceNumber_(0)
	, recvSequenceNumber_(0)

	, securityMode_(SM_None)
	, securityPolicy_(SP_None)
	{
	}

	SecureChannel::~SecureChannel(void)
	{
	}

	void
	SecureChannel::debugRead(const std::string& message)
	{
		Log(Debug, "opc ua secure channel read")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("Message", message);
	}

	void
	SecureChannel::debugRecvHeader(MessageHeader& messageHeader)
	{
		if (!debugHeader_) return;

		std::string messageType = "Unknown";
		switch(messageHeader.messageType())
		{
			case MessageType_Hello: messageType = "Hello"; break;
			case MessageType_Acknowledge: messageType = "Acknowledge"; break;
			case MessageType_OpenSecureChannel: messageType = "OpenSecureChannel"; break;
			case MessageType_CloseSecureChannel: messageType = "CloseSecureChannel"; break;
			case MessageType_Error: messageType = "Error"; break;
			case MessageType_Message: messageType = "Message"; break;
		}

		Log(Debug, "opc ua secure channel recv Header")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("SegmentFlag", messageHeader.segmentFlag())
			.parameter("MessageType", messageType)
			.parameter("MessageSize", messageHeader.messageSize());
	}

	void
	SecureChannel::debugReadHello(void)
	{
		if (!debug_) return;
		debugRead("Hello");
	}

	void
	SecureChannel::debugRecvAcknowledge(AcknowledgeMessage& acknowledge)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel recv Acknowledge")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ReceivedBufferSize", acknowledge.receivedBufferSize())
			.parameter("SendBufferSize", acknowledge.sendBufferSize())
			.parameter("MaxMessageSize", acknowledge.maxMessageSize())
			.parameter("MaxChunkCount", acknowledge.maxChunkCount());
	}

	void
	SecureChannel::debugReadOpenSecureChannelRequest(void)
	{
		if (!debug_) return;
		debugRead("OpenSecureChannelRequest");
	}

	void
	SecureChannel::debugReadOpenSecureChannelResponse(void)
	{
		if (!debug_) return;
		debugRead("OpenSecureChannelResponse");
	}

	void
	SecureChannel::debugReadCloseSecureChannelRequest(void)
	{
		if (!debug_) return;
		debugRead("CloseSecureChannelRequest");
	}

	void
	SecureChannel::debugReadCloseSecureChannelResponse(void)
	{
		if (!debug_) return;
		debugRead("CloseSecureChannelResponse");
	}

	void
	SecureChannel::debugReadMessageRequest(void)
	{
		if (!debug_) return;
		debugRead("MessageRequest");
	}

	void
	SecureChannel::debugReadMessageResponse(void)
	{
		if (!debug_) return;
		debugRead("MessageResponse");
	}

	void
	SecureChannel::debugWrite(const std::string& message)
	{
		Log(Debug, "opc ua secure channel write")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("Message", message);
	}

	void
	SecureChannel::debugSendHeader(MessageHeader& messageHeader)
	{
		if (!debugHeader_) return;

		std::string messageType = "Unknown";
		switch(messageHeader.messageType())
		{
			case MessageType_Hello: messageType = "Hello"; break;
			case MessageType_Acknowledge: messageType = "Acknowledge"; break;
			case MessageType_OpenSecureChannel: messageType = "OpenSecureChannel"; break;
			case MessageType_CloseSecureChannel: messageType = "CloseSecureChannel"; break;
			case MessageType_Error: messageType = "Error"; break;
			case MessageType_Message: messageType = "Message"; break;
		}

		Log(Debug, "opc ua secure channel send Header")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("SegmentFlag", messageHeader.segmentFlag())
			.parameter("MessageType", messageType)
			.parameter("MessageSize", messageHeader.messageSize());
	}

	void
	SecureChannel::debugSendHello(HelloMessage& hello)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel send Hello")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ReceivedBufferSize", hello.receivedBufferSize())
			.parameter("SendBufferSize", hello.sendBufferSize())
			.parameter("MaxMessageSize", hello.maxMessageSize())
			.parameter("MaxChunkCount", hello.maxChunkCount())
			.parameter("EndpointUrl", hello.endpointUrl());
	}

	void
	SecureChannel::debugSendOpenSecureChannel(OpenSecureChannelRequest& openSecureChannelRequest)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel send Hello")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("RequestType", openSecureChannelRequest.requestType())
			.parameter("SecurityMode", openSecureChannelRequest.securityMode())
			.parameter("RequestedLifetime", openSecureChannelRequest.requestedLifetime());
	}

}


