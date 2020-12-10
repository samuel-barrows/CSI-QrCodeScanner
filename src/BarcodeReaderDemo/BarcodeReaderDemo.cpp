#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "DynamsoftBarcodeReader.h"
//#include "DynamsoftCommon.h"
using namespace dynamsoft::dbr;
/*typedef struct BarcodeFormatSet
{
	int barcodeFormatIds;
	int barcodeFormatIds_2;
}BarcodeFormatSet;

/*
  const int GetBarcodeFormatId(int iIndex, BarcodeFormatSet* barcodeFormatSet)

  {
	int ret = 0;
  barcodeFormatSet->barcodeFormatIds = BF_QR_CODE;
  barcodeFormatSet->barcodeFormatIds_2 = 0;
	return ret;
  }


bool GetImagePath(char* pImagePath)
{
	char pszBuffer[512] = { 0 };
	bool bExit = false;
	size_t iLen = 0;
	FILE* fp = NULL;
	while (1)
	{
		printf("\r\n>> Step 1: Input your image file's full path:\r\n");
		fgets(pszBuffer, 512, stdin);
		strtok(pszBuffer, "\n");

		iLen = strlen(pszBuffer);
		if (iLen > 0)
		{
			if (strlen(pszBuffer) == 1 && (pszBuffer[0] == 'q' || pszBuffer[0] == 'Q'))
			{
				bExit = true;
				break;
			}

			memset(pImagePath, 0, 512);
			if (pszBuffer[0] == '\'')
			{
				if(pszBuffer[iLen - 3] == '\'')
					memcpy(pImagePath, pszBuffer + 1, iLen - 4);
				else if(pszBuffer[iLen - 2] == '\'')
					memcpy(pImagePath, pszBuffer + 1, iLen - 3);
			}
			else
				memcpy(pImagePath, pszBuffer, iLen);

			fp = fopen(pImagePath, "rb");
			if (fp != NULL)
			{
				break;
			}
		}
		printf("Please input a valid path.\r\n");
	}
	return bExit;
}
/*
 *
 bool SetBarcodeFormat(BarcodeFormatSet* iBarcodeFormatId)
 {
 bool bExit = false;
 return bExit;
 }

void OutputResult(CBarcodeReader& reader, int errorcode)
{
	char * pszTemp = NULL;
	int iRet = errorcode;
	pszTemp = (char*)malloc(4096);
	if (iRet != DBR_OK && iRet != DBRERR_MAXICODE_LICENSE_INVALID && iRet != DBRERR_AZTEC_LICENSE_INVALID && iRet != DBRERR_LICENSE_EXPIRED && iRet != DBRERR_QR_LICENSE_INVALID && iRet != DBRERR_GS1_COMPOSITE_LICENSE_INVALID &&
		iRet != DBRERR_1D_LICENSE_INVALID && iRet != DBRERR_PDF417_LICENSE_INVALID && iRet != DBRERR_DATAMATRIX_LICENSE_INVALID && iRet != DBRERR_GS1_DATABAR_LICENSE_INVALID && iRet != DBRERR_PATCHCODE_LICENSE_INVALID &&
		iRet != DBRERR_POSTALCODE_LICENSE_INVALID && iRet != DBRERR_DOTCODE_LICENSE_INVALID && iRet != DBRERR_DPM_LICENSE_INVALID && iRet != DBRERR_IRT_LICENSE_INVALID)
	{
		snprintf(pszTemp, 4096, "Failed to read barcode: %s\r\n", CBarcodeReader::GetErrorString(iRet));
		printf("%s", pszTemp);
		free(pszTemp);
		return;
	}

	TextResultArray *paryResult = NULL;
	//reader.GetAllTextResults(&paryResult);

	if (paryResult->resultsCount == 0)
	{
		printf("%s", pszTemp);
		free(pszTemp);
		CBarcodeReader::FreeTextResults(&paryResult);
		return;
	}

	for (int iIndex = 0; iIndex < paryResult->resultsCount; iIndex++)
	{
    std::cout << paryResult->results[iIndex]->barcodeText << std::endl;
	}

	free(pszTemp);
	CBarcodeReader::FreeTextResults(&paryResult);
}

*/
int BarcodeScan(char path[512])
{
	const char* pszTemplateName = NULL;
	//BarcodeFormatSet iBarcodeFormatId = { 0,0 };
  //char* pszImageFile[512] = path;
	int iRet = -1;

	CBarcodeReader reader;
	reader.InitLicense("t0068NQAAAC2twMVVLoH0MeCgyjaW/crdFW0D2PS21uV8pfpD/nkzlqx13pKgUVaAvKFO/h26EDNvnISsmJNu6SsycQoQZG4=");

  //Best coverage settings
  //reader->InitRuntimeSettingsWithString("{\"ImageParameter\":{\"Name\":\"BestCoverage\",\"DeblurLevel\":9,\"ExpectedBarcodesCount\":512,\"ScaleDownThreshold\":100000,\"LocalizationModes\":[{\"Mode\":\"LM_CONNECTED_BLOCKS\"},{\"Mode\":\"LM_SCAN_DIRECTLY\"},{\"Mode\":\"LM_STATISTICS\"},{\"Mode\":\"LM_LINES\"},{\"Mode\":\"LM_STATISTICS_MARKS\"}],\"GrayscaleTransformationModes\":[{\"Mode\":\"GTM_ORIGINAL\"},{\"Mode\":\"GTM_INVERTED\"}]}}", CM_OVERWRITE, szErrorMsg, 256);
  //reader->GetRuntimeSettings(&runtimeSettings);
  //runtimeSettings.barcodeFormatIds = iBarcodeFormatId.barcodeFormatIds;
  //runtimeSettings.barcodeFormatIds_2 = iBarcodeFormatId.barcodeFormatIds_2;
  //iRet = reader->UpdateRuntimeSettings(&runtimeSettings, szErrorMsg, 256);
  //if (iRet != DBR_OK)
  // {
  //	printf("Error code: %d. Error message: %s\n", iRet, szErrorMsg);
  //	return false;
  //}

  //OutputResult(reader, iRet);
  TextResultArray* pResults;
  iRet = reader.DecodeFile(path, pszTemplateName);
  reader.GetAllTextResults(&pResults);
  dynamsoft::dbr::CBarcodeReader::FreeTextResults(&pResults);


  /*
  CBarcodeReader* reader = new CBarcodeReader();
  reader->InitLicense("t0260NwAAAHV***************");
  int errorCode = reader->DecodeFile("C:\\Program Files (x86)\\Dynamsoft\\{Version number}\\Images\\AllSupportedBarcodeTypes.tif", "");
  const char* errorString = CBarcodeReader::GetErrorString(errorCode);
  delete reader;
  */
  return 0;
}

