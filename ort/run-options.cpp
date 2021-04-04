extern "C" {
    #include <onnxruntime_c_api.h>
    #include "run-options.h"

    OrtCreateRunOptionsResponse createRunOptions(OrtApi *api, OrtCreateRunOptionsParameters *params) {
    	OrtStatus *status;
    	OrtRunOptions *options;

    	status = api->CreateRunOptions(&options);
    	if(status != NULL){
            releaseRunOptions(api, options);
	        return respondRunOptionsErrorStatus(status);
    	}

    	if(params->tag != NULL) {
    		status = api->RunOptionsSetRunTag(options, params->tag);
    		if(status != NULL) {
                releaseRunOptions(api, options);
	            return respondRunOptionsErrorStatus(status);
    		}
    	}
        if(params->logVerbosityLevel > 0) {
            status = api->RunOptionsSetRunLogVerbosityLevel(options, params->logVerbosityLevel);
            if(status != NULL) {
                releaseRunOptions(api, options);
	            return respondRunOptionsErrorStatus(status);
            }
        }
        if(params->logSeverityLevel > 0) {
            status = api->RunOptionsSetRunLogSeverityLevel(options, params->logSeverityLevel);
            if(status != NULL) {
                releaseRunOptions(api, options);
	            return respondRunOptionsErrorStatus(status);
            }
        }
        if(params->terminate == 1) {
        	status = api->RunOptionsSetTerminate(options);
        	if(status != NULL) {
                releaseRunOptions(api, options);
	            return respondRunOptionsErrorStatus(status);
        	}
        }

        OrtCreateRunOptionsResponse response;
        response.runOptions = options;
        response.status = NULL;

        return response;
    }

	void releaseRunOptions(OrtApi *api, OrtRunOptions *runOptions) {
	    api->ReleaseRunOptions(runOptions);
	}

    OrtCreateRunOptionsResponse respondRunOptionsErrorStatus(OrtStatus *status) {
	    OrtCreateRunOptionsResponse response;
	    response.status = status;
	    response.runOptions = NULL;
	    return response;
	}
}
