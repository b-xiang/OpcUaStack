/*
    VariableTypeClass: OptionSetType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_OptionSetType_h__
#define __OpcUaStackServer_OptionSetType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT OptionSetType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<OptionSetType> SPtr;
       typedef std::vector<OptionSetType::SPtr> Vec;
   
       OptionSetType(void);
       OptionSetType(const OptionSetType& value);
       virtual ~OptionSetType(void);

        void bitMask_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& bitMask_Variable(void);
        bool get_BitMask_Variable(OpcUaDataValue& dataValue);
        bool set_BitMask_Variable(const OpcUaDataValue& dataValue);

        void optionSetValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& optionSetValues_Variable(void);
        bool get_OptionSetValues_Variable(OpcUaDataValue& dataValue);
        bool set_OptionSetValues_Variable(const OpcUaDataValue& dataValue);

        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr bitMask_Variable_;
        ServerVariable::SPtr optionSetValues_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif