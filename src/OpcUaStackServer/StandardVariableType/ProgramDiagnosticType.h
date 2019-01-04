/*
    VariableTypeClass: ProgramDiagnosticType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ProgramDiagnosticType_h__
#define __OpcUaStackServer_ProgramDiagnosticType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ProgramDiagnosticType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<ProgramDiagnosticType> SPtr;
       typedef std::vector<ProgramDiagnosticType::SPtr> Vec;
   
       ProgramDiagnosticType(void);
       ProgramDiagnosticType(const ProgramDiagnosticType& value);
       virtual ~ProgramDiagnosticType(void);

        void createClientName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& createClientName_Variable(void);
        bool get_CreateClientName_Variable(OpcUaDataValue& dataValue);
        bool set_CreateClientName_Variable(const OpcUaDataValue& dataValue);

        void createSessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& createSessionId_Variable(void);
        bool get_CreateSessionId_Variable(OpcUaDataValue& dataValue);
        bool set_CreateSessionId_Variable(const OpcUaDataValue& dataValue);

        void invocationCreationTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& invocationCreationTime_Variable(void);
        bool get_InvocationCreationTime_Variable(OpcUaDataValue& dataValue);
        bool set_InvocationCreationTime_Variable(const OpcUaDataValue& dataValue);

        void lastMethodCallTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodCallTime_Variable(void);
        bool get_LastMethodCallTime_Variable(OpcUaDataValue& dataValue);
        bool set_LastMethodCallTime_Variable(const OpcUaDataValue& dataValue);

        void lastMethodCall_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodCall_Variable(void);
        bool get_LastMethodCall_Variable(OpcUaDataValue& dataValue);
        bool set_LastMethodCall_Variable(const OpcUaDataValue& dataValue);

        void lastMethodInputArguments_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodInputArguments_Variable(void);
        bool get_LastMethodInputArguments_Variable(OpcUaDataValue& dataValue);
        bool set_LastMethodInputArguments_Variable(const OpcUaDataValue& dataValue);

        void lastMethodOutputArguments_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodOutputArguments_Variable(void);
        bool get_LastMethodOutputArguments_Variable(OpcUaDataValue& dataValue);
        bool set_LastMethodOutputArguments_Variable(const OpcUaDataValue& dataValue);

        void lastMethodReturnStatus_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodReturnStatus_Variable(void);
        bool get_LastMethodReturnStatus_Variable(OpcUaDataValue& dataValue);
        bool set_LastMethodReturnStatus_Variable(const OpcUaDataValue& dataValue);

        void lastMethodSessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastMethodSessionId_Variable(void);
        bool get_LastMethodSessionId_Variable(OpcUaDataValue& dataValue);
        bool set_LastMethodSessionId_Variable(const OpcUaDataValue& dataValue);

        void lastTransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastTransitionTime_Variable(void);
        bool get_LastTransitionTime_Variable(OpcUaDataValue& dataValue);
        bool set_LastTransitionTime_Variable(const OpcUaDataValue& dataValue);

        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr createClientName_Variable_;
        ServerVariable::SPtr createSessionId_Variable_;
        ServerVariable::SPtr invocationCreationTime_Variable_;
        ServerVariable::SPtr lastMethodCallTime_Variable_;
        ServerVariable::SPtr lastMethodCall_Variable_;
        ServerVariable::SPtr lastMethodInputArguments_Variable_;
        ServerVariable::SPtr lastMethodOutputArguments_Variable_;
        ServerVariable::SPtr lastMethodReturnStatus_Variable_;
        ServerVariable::SPtr lastMethodSessionId_Variable_;
        ServerVariable::SPtr lastTransitionTime_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif