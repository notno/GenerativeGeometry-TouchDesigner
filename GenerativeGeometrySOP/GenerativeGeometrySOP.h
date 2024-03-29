#pragma once
/* Shared Use License: This file is owned by Derivative Inc. (Derivative) and
* can only be used, and/or modified for use, in conjunction with
* Derivative's TouchDesigner software, and only if you are a licensee who has
* accepted Derivative's TouchDesigner license or assignment agreement (which
* also govern the use of this file).  You may share a modified version of this
* file with another authorized licensee of Derivative's TouchDesigner software.
* Otherwise, no redistribution or sharing of this file, with or without
* modification, is permitted.
*/

#include "SOP_CPlusPlusBase.h"
#include <string>



// To get more help about these functions, look at SOP_CPlusPlusBase.h
class GenerativeGeometrySOP : public SOP_CPlusPlusBase
{
public:

	GenerativeGeometrySOP(const OP_NodeInfo* info);

	virtual ~GenerativeGeometrySOP();

	virtual void	getGeneralInfo(SOP_GeneralInfo*, const OP_Inputs*, void* reserved1) override;

	virtual void	execute(SOP_Output*, const OP_Inputs*, void* reserved) override;


	virtual void executeVBO(SOP_VBOOutput* output, const OP_Inputs* inputs,
							void* reserved) override;


	virtual int32_t getNumInfoCHOPChans(void* reserved) override;

	virtual void getInfoCHOPChan(int index, OP_InfoCHOPChan* chan, void* reserved) override;

	virtual bool getInfoDATSize(OP_InfoDATSize* infoSize, void* reserved) override;

	virtual void getInfoDATEntries(int32_t index, int32_t nEntries,
									OP_InfoDATEntries* entries,
									void* reserved) override;

	virtual void setupParameters(OP_ParameterManager* manager, void* reserved) override;
	virtual void pulsePressed(const char* name, void* reserved) override;

private:

	// example functions for generating a geometry, change them with any
	// fucntions and algorithm:

	void cubeGeometry(SOP_Output* output, float scale = 1.0f);

	void lineGeometry(SOP_Output* output);

	void triangleGeometry(SOP_Output* output);

	void circleGeometry(SOP_Output* output); // GenerativeGeometry
	void gear2DGeometry(SOP_Output* output); // GenerativeGeometry
	void gear3DGeometry(SOP_Output* output); // GenerativeGeometry

	void cubeGeometryVBO(SOP_VBOOutput* output, float scale = 1.0f);

	void lineGeometryVBO(SOP_VBOOutput* output);

	void triangleGeometryVBO(SOP_VBOOutput* output);

	void particleGeometryVBO(SOP_VBOOutput* output);


	// We don't need to store this pointer, but we do for the example.
	// The OP_NodeInfo class store information about the node that's using
	// this instance of the class (like its name).
	const OP_NodeInfo*		myNodeInfo;

	// In this example this value will be incremented each time the execute()
	// function is called, then passes back to the SOP
	int32_t					myExecuteCount;


	double					myOffset;
	std::string             myChopChanName;
	float                   myChopChanVal;
	std::string             myChop;

	std::string             myDat;

	int						myNumVBOTexLayers;
};