/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/EventType/EventVariables.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// class EventVariable
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	EventVariable::EventVariable(OpcUaBuildInType buildInType)
	: variable_()
	, buildInType_(buildInType)
	{
	}

	EventVariable::~EventVariable(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// class EventVariables
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	EventVariables::EventVariables(void)
	: eventVariableMap_()
	,namespaceIndex_(0)
	{
	}

	EventVariables::~EventVariables(void)
	{
	}

	void
	EventVariables::namespaceIndex(uint32_t namespaceIndex)
	{
		namespaceIndex_ = namespaceIndex;
	}

	uint32_t
	EventVariables::namespaceIndex(void)
	{
		return namespaceIndex_;
	}

	bool
	EventVariables::registerEventVariable(const std::string& variableName, OpcUaBuildInType buildInType)
	{
		EventVariableMap::iterator it;
		it = eventVariableMap_.find(variableName);
		if (it != eventVariableMap_.end()) {
			return false;
		}

		EventVariable eventVariable(buildInType);
		eventVariableMap_.insert(std::make_pair(variableName, eventVariable));
		return true;
	}

	bool
	EventVariables::deregisterEventVariable(const std::string& variableName)
	{
		EventVariableMap::iterator it;
		it = eventVariableMap_.find(variableName);
		if (it == eventVariableMap_.end()) {
			return true;
		}
		eventVariableMap_.erase(it);
		return true;
	}

	bool
	EventVariables::setValue(const std::string& variableName, OpcUaVariant::SPtr& value)
	{
		if (value.get() == nullptr) {
			return false;
		}

		EventVariableMap::iterator it;
		it = eventVariableMap_.find(variableName);
		if (it == eventVariableMap_.end()) {
			return false;
		}

		if (value->variantType() != it->second.buildInType_) {
			return false;
		}

		it->second.variable_ = value;
		return true;
	}

	bool
	EventVariables::getValue(const std::string& variableName, OpcUaVariant::SPtr& variable)
	{
		EventVariableMap::iterator it;
		it = eventVariableMap_.find(variableName);
		if (it == eventVariableMap_.end()) {
			variable.reset();
			return false;
		}

		variable = it->second.variable_;
		return true;
	}

	OpcUaVariant::SPtr
	EventVariables::get(OpcUaQualifiedName::SPtr& browseName, EventResult::Code& resultCode)
	{
		EventVariableMap::iterator it;

		resultCode = EventResult::Success;
		for (it = eventVariableMap_.begin(); it != eventVariableMap_.end(); it++) {
			if (*browseName == OpcUaQualifiedName(it->first, namespaceIndex_)) {
				OpcUaVariant::SPtr variant;
				if (it->second.variable_.get() == nullptr) {
					resultCode = EventResult::BadValueNotExist;
				}
				return it->second.variable_;
			}
		}

		resultCode = EventResult::BadBrowseNameNotExist;
		OpcUaVariant::SPtr variant;
		return variant;
	}

	OpcUaVariant::SPtr
	EventVariables::get(std::list<OpcUaQualifiedName::SPtr>& browseNameList, EventResult::Code& resultCode)
	{
		OpcUaVariant::SPtr variant;

		OpcUaQualifiedName::SPtr browseName = browseNameList.front();
		variant = get(browseName, resultCode);

		if (resultCode == EventResult::Success) {
			browseNameList.pop_front();
		}

		resultCode = EventResult::Success;
		return variant;
	}

}
