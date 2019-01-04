/*
    VariableTypeClass: FiniteStateVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_FiniteStateVariableType_h__
#define __OpcUaStackServer_FiniteStateVariableType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT FiniteStateVariableType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<FiniteStateVariableType> SPtr;
       typedef std::vector<FiniteStateVariableType::SPtr> Vec;
   
       FiniteStateVariableType(void);
       FiniteStateVariableType(const FiniteStateVariableType& value);
       virtual ~FiniteStateVariableType(void);

        void effectiveDisplayName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& effectiveDisplayName_Variable(void);
        bool get_EffectiveDisplayName_Variable(OpcUaDataValue& dataValue);
        bool set_EffectiveDisplayName_Variable(const OpcUaDataValue& dataValue);

        void id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& id_Variable(void);
        bool get_Id_Variable(OpcUaDataValue& dataValue);
        bool set_Id_Variable(const OpcUaDataValue& dataValue);

        void name_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& name_Variable(void);
        bool get_Name_Variable(OpcUaDataValue& dataValue);
        bool set_Name_Variable(const OpcUaDataValue& dataValue);

        void number_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& number_Variable(void);
        bool get_Number_Variable(OpcUaDataValue& dataValue);
        bool set_Number_Variable(const OpcUaDataValue& dataValue);

        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr effectiveDisplayName_Variable_;
        ServerVariable::SPtr id_Variable_;
        ServerVariable::SPtr name_Variable_;
        ServerVariable::SPtr number_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif