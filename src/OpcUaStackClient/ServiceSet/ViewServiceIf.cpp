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


#include "OpcUaStackClient/ServiceSet/ViewServiceIf.h"

namespace OpcUaStackClient
{
	ViewServiceIfTestHandler::ViewServiceIfTestHandler(void)
	: viewServiceBrowseResponse_()
	, viewServiceBrowseNextResponse_()
	, viewServiceTranslateBrowsePathsToNodeIdsResponse_()
	{
	}

	ViewServiceIfTestHandler::~ViewServiceIfTestHandler(void)
	{
	}

    void
    ViewServiceIfTestHandler::viewServiceBrowseResponse(ServiceTransactionBrowse::SPtr serviceTransactionBrowse)
    {
    	viewServiceBrowseResponse_.conditionValueDec();
    }

    void
    ViewServiceIfTestHandler::viewServiceBrowseNextResponse(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext)
    {
    	viewServiceBrowseNextResponse_.conditionValueDec();
    }

    void
    ViewServiceIfTestHandler::viewServiceTranslateBrowsePathsToNodeIdsResponse(ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTranslateBrowsePathsToNodeIds)
    {
    	viewServiceTranslateBrowsePathsToNodeIdsResponse_.conditionValueDec();
    }

}
