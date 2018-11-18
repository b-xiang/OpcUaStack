/*
    DataTypeClass: StructureDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/StructureDescription.h"

namespace OpcUaStackCore
{
    
    StructureDescription::StructureDescription(void)
    : DataTypeDescription()
    , structureDefinition_()
    {
    }
    
    StructureDescription::~StructureDescription(void)
    {
    }
    
    StructureDefinition&
    StructureDescription::structureDefinition(void)
    {
        return structureDefinition_;
    }
    
    bool
    StructureDescription::operator==(const StructureDescription& value)
    {
        StructureDescription* dst = const_cast<StructureDescription*>(&value);
        if (structureDefinition_ != dst->structureDefinition()) return false;
        return true;
    }
    
    bool
    StructureDescription::operator!=(const StructureDescription& value)
    {
        return !this->operator==(value);
    }
    
    void
    StructureDescription::copyTo(StructureDescription& value)
    {
        structureDefinition_.copyTo(value.structureDefinition());
    }
    
    StructureDescription&
    StructureDescription::operator=(const StructureDescription& value)
    {
        const_cast<StructureDescription*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    StructureDescription::factory(void)
    {
    	return constructSPtr<StructureDescription>();
    }
    
    std::string
    StructureDescription::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    StructureDescription::typeName(void)
    {
    	return "StructureDescription";
    }
    
    OpcUaNodeId
    StructureDescription::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15487,0);
    }
    
    OpcUaNodeId
    StructureDescription::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)126, 0);
    }
    
    OpcUaNodeId
    StructureDescription::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15589, 0);
    }
    
    OpcUaNodeId
    StructureDescription::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15058, 0);
    }
    
    void
    StructureDescription::opcUaBinaryEncode(std::ostream& os) const
    {
        structureDefinition_.opcUaBinaryEncode(os);
    }
    
    void
    StructureDescription::opcUaBinaryDecode(std::istream& is)
    {
        structureDefinition_.opcUaBinaryDecode(is);
    }
    
    bool
    StructureDescription::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    StructureDescription::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    StructureDescription::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    StructureDescription::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!structureDefinition_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StructureDefinition", elementTree));
    
        return true;
    }
    
    bool
    StructureDescription::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StructureDescription::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("StructureDefinition");
        if (!tree) return false;
        if (!structureDefinition_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    StructureDescription::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    StructureDescription::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    StructureDescription::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    StructureDescription::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    StructureDescription::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	StructureDescription* dst = dynamic_cast<StructureDescription*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    StructureDescription::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	StructureDescription* dst = dynamic_cast<StructureDescription*>(&extensionObjectBase);
    	return *const_cast<StructureDescription*>(this) == *dst;
    }
    
    void
    StructureDescription::out(std::ostream& os)
    {
        os << "StructureDefinition="; structureDefinition_.out(os);
    }

}