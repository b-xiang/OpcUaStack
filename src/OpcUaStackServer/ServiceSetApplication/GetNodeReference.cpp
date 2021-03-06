/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetApplication/GetNodeReference.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

namespace OpcUaStackServer
{

	GetNodeReference::GetNodeReference(void)
	: nodes_()
	, resultCode_(Success)
	, statuses_()
	, nodeReferences_()
	{
	}

	GetNodeReference::GetNodeReference(const OpcUaNodeId& node)
	: nodes_()
	, resultCode_(Success)
	, statuses_()
	, nodeReferences_()
	{
		nodes_.push_back(node);
	}

	GetNodeReference::GetNodeReference(const std::vector<OpcUaNodeId>& nodes)
	: nodes_(nodes)
	, resultCode_(Success)
	, statuses_()
	, nodeReferences_()
	{
	}

	GetNodeReference::~GetNodeReference(void)
	{
	}

	void
	GetNodeReference::addNode(const OpcUaNodeId& node)
	{
		nodes_.push_back(node);
	}

	void
	GetNodeReference::addNodes(const std::vector<OpcUaNodeId>& nodes)
	{
		nodes_.insert(nodes_.end(), nodes.begin(), nodes.end());
	}

	void
	GetNodeReference::node(const OpcUaNodeId& node)
	{
		nodes_.clear();
		nodes_.push_back(node);
	}

	void
	GetNodeReference::nodes(const std::vector<OpcUaNodeId>& nodes)
	{
		nodes_ = nodes;
	}

	std::vector<OpcUaNodeId>&
	GetNodeReference::nodes(void)
	{
		return nodes_;
	}

	bool
	GetNodeReference::query(ApplicationServiceIf* applicationServiceIf)
	{
		if (nodes_.size() == 0) return false;

		resultCode_ = Success;
		statuses_.clear();
		nodeReferences_.clear();

		// create request
		auto trx = constructSPtr<ServiceTransactionGetNodeReference>();
		trx->request()->nodes()->resize(nodes_.size());
		for (auto node : nodes_) trx->request()->nodes()->push_back(constructSPtr<OpcUaNodeId>(node));

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) return false;

	  	// handle response
	  	for (uint32_t idx = 0; idx < trx->response()->nodeReferenceArray()->size(); idx++) {
	  		NodeReference::SPtr nodeReference;
	  		trx->response()->nodeReferenceArray()->get(idx, nodeReference);
	  		NodeReferenceApplication::SPtr nodeReferenceApplication = boost::static_pointer_cast<NodeReferenceApplication>(nodeReference);
	  		nodeReferences_.push_back(nodeReferenceApplication->baseNodeClass());
	  		statuses_.push_back(nodeReferenceApplication->statusCode());
	  	}

		return true;
	}

	OpcUaStatusCode
	GetNodeReference::resultCode(void)
	{
		return resultCode_;
	}

	std::vector<OpcUaStatusCode>&
	GetNodeReference::statuses(void)
	{
		return statuses_;
	}

	std::vector<BaseNodeClass::WPtr>&
	GetNodeReference::nodeReferences(void)
	{
		return nodeReferences_;
	}

}
