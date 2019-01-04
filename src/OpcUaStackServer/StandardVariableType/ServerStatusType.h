/*
    VariableTypeClass: ServerStatusType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerStatusType_h__
#define __OpcUaStackServer_ServerStatusType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ServerStatusType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<ServerStatusType> SPtr;
       typedef std::vector<ServerStatusType::SPtr> Vec;
   
       ServerStatusType(void);
       ServerStatusType(const ServerStatusType& value);
       virtual ~ServerStatusType(void);

        void buildInfo_BuildDate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_BuildDate_Variable(void);
        bool get_BuildInfo_BuildDate_Variable(OpcUaDataValue& dataValue);
        bool set_BuildInfo_BuildDate_Variable(const OpcUaDataValue& dataValue);

        void buildInfo_BuildNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_BuildNumber_Variable(void);
        bool get_BuildInfo_BuildNumber_Variable(OpcUaDataValue& dataValue);
        bool set_BuildInfo_BuildNumber_Variable(const OpcUaDataValue& dataValue);

        void buildInfo_ManufacturerName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_ManufacturerName_Variable(void);
        bool get_BuildInfo_ManufacturerName_Variable(OpcUaDataValue& dataValue);
        bool set_BuildInfo_ManufacturerName_Variable(const OpcUaDataValue& dataValue);

        void buildInfo_ProductName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_ProductName_Variable(void);
        bool get_BuildInfo_ProductName_Variable(OpcUaDataValue& dataValue);
        bool set_BuildInfo_ProductName_Variable(const OpcUaDataValue& dataValue);

        void buildInfo_ProductUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_ProductUri_Variable(void);
        bool get_BuildInfo_ProductUri_Variable(OpcUaDataValue& dataValue);
        bool set_BuildInfo_ProductUri_Variable(const OpcUaDataValue& dataValue);

        void buildInfo_SoftwareVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_SoftwareVersion_Variable(void);
        bool get_BuildInfo_SoftwareVersion_Variable(OpcUaDataValue& dataValue);
        bool set_BuildInfo_SoftwareVersion_Variable(const OpcUaDataValue& dataValue);

        void buildInfo_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildInfo_Variable(void);
        bool get_BuildInfo_Variable(OpcUaDataValue& dataValue);
        bool set_BuildInfo_Variable(const OpcUaDataValue& dataValue);

        void currentTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentTime_Variable(void);
        bool get_CurrentTime_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentTime_Variable(const OpcUaDataValue& dataValue);

        void secondsTillShutdown_BuildDate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& secondsTillShutdown_BuildDate_Variable(void);
        bool get_SecondsTillShutdown_BuildDate_Variable(OpcUaDataValue& dataValue);
        bool set_SecondsTillShutdown_BuildDate_Variable(const OpcUaDataValue& dataValue);

        void shutdownReason_BuildDate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& shutdownReason_BuildDate_Variable(void);
        bool get_ShutdownReason_BuildDate_Variable(OpcUaDataValue& dataValue);
        bool set_ShutdownReason_BuildDate_Variable(const OpcUaDataValue& dataValue);

        void startTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& startTime_Variable(void);
        bool get_StartTime_Variable(OpcUaDataValue& dataValue);
        bool set_StartTime_Variable(const OpcUaDataValue& dataValue);

        void state_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& state_Variable(void);
        bool get_State_Variable(OpcUaDataValue& dataValue);
        bool set_State_Variable(const OpcUaDataValue& dataValue);

        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr buildInfo_BuildDate_Variable_;
        ServerVariable::SPtr buildInfo_BuildNumber_Variable_;
        ServerVariable::SPtr buildInfo_ManufacturerName_Variable_;
        ServerVariable::SPtr buildInfo_ProductName_Variable_;
        ServerVariable::SPtr buildInfo_ProductUri_Variable_;
        ServerVariable::SPtr buildInfo_SoftwareVersion_Variable_;
        ServerVariable::SPtr buildInfo_Variable_;
        ServerVariable::SPtr currentTime_Variable_;
        ServerVariable::SPtr secondsTillShutdown_BuildDate_Variable_;
        ServerVariable::SPtr shutdownReason_BuildDate_Variable_;
        ServerVariable::SPtr startTime_Variable_;
        ServerVariable::SPtr state_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif