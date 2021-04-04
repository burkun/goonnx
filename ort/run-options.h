#ifndef GOONNX_RUN_OPTIONS
#define GOONNX_RUN_OPTIONS

#include <onnxruntime_c_api.h>
typedef struct OrtCreateRunOptionsParameters {
	const char *tag;
	int logVerbosityLevel;
	int logSeverityLevel;
	int terminate;
} OrtCreateRunOptionsParameters;

typedef struct OrtCreateRunOptionsResponse {
	OrtRunOptions *runOptions;
	OrtStatus *status;
} OrtCreateRunOptionsResponse;

OrtCreateRunOptionsResponse createRunOptions(OrtApi *api, OrtCreateRunOptionsParameters *params);
void releaseRunOptions(OrtApi *api, OrtRunOptions *runOptions);
OrtCreateRunOptionsResponse respondRunOptionsErrorStatus(OrtStatus *status);

#endif
