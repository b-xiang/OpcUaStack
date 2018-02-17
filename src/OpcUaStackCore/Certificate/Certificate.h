/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Certificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_Certificate_h__
#define __OpcUaStackCore_Certificate_h__

#include <vector>
#include <string>
#include <openssl/x509.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/CertificateEnums.h"
#include "OpcUaStackCore/Certificate/Info.h"
#include "OpcUaStackCore/Certificate/Identity.h"
#include "OpcUaStackCore/Certificate/RSAKey.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Certificate
	: public OpenSSLError
	{
	  public:
		Certificate(void);
		Certificate(
			const Info& info,
			const Identity& subject,
		    const RSAKey& rsaKey,
		    bool bCACert = false,
		    SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1
		);
		~Certificate(void);

	  private:
		X509 *cert_;
	};

}

#endif