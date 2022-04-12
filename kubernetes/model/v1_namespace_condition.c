#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_namespace_condition.h"


char* typev1_namespace_condition_ToString(kubernetes_v1_namespace_condition_TYPE_e type) {
    char* typeArray[] =  { "NULL", "NamespaceContentRemaining", "NamespaceDeletionContentFailure", "NamespaceDeletionDiscoveryFailure", "NamespaceDeletionGroupVersionParsingFailure", "NamespaceFinalizersRemaining" };
	return typeArray[type];
}

kubernetes_v1_namespace_condition_TYPE_e typev1_namespace_condition_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "NamespaceContentRemaining", "NamespaceDeletionContentFailure", "NamespaceDeletionDiscoveryFailure", "NamespaceDeletionGroupVersionParsingFailure", "NamespaceFinalizersRemaining" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

v1_namespace_condition_t *v1_namespace_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    kubernetes_v1_namespace_condition_TYPE_e type
    ) {
    v1_namespace_condition_t *v1_namespace_condition_local_var = malloc(sizeof(v1_namespace_condition_t));
    if (!v1_namespace_condition_local_var) {
        return NULL;
    }
    v1_namespace_condition_local_var->last_transition_time = last_transition_time;
    v1_namespace_condition_local_var->message = message;
    v1_namespace_condition_local_var->reason = reason;
    v1_namespace_condition_local_var->status = status;
    v1_namespace_condition_local_var->type = type;

    return v1_namespace_condition_local_var;
}


void v1_namespace_condition_free(v1_namespace_condition_t *v1_namespace_condition) {
    if(NULL == v1_namespace_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_namespace_condition->last_transition_time) {
        free(v1_namespace_condition->last_transition_time);
        v1_namespace_condition->last_transition_time = NULL;
    }
    if (v1_namespace_condition->message) {
        free(v1_namespace_condition->message);
        v1_namespace_condition->message = NULL;
    }
    if (v1_namespace_condition->reason) {
        free(v1_namespace_condition->reason);
        v1_namespace_condition->reason = NULL;
    }
    if (v1_namespace_condition->status) {
        free(v1_namespace_condition->status);
        v1_namespace_condition->status = NULL;
    }
    free(v1_namespace_condition);
}

cJSON *v1_namespace_condition_convertToJSON(v1_namespace_condition_t *v1_namespace_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1_namespace_condition->last_transition_time
    if(v1_namespace_condition->last_transition_time) { 
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1_namespace_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // v1_namespace_condition->message
    if(v1_namespace_condition->message) { 
    if(cJSON_AddStringToObject(item, "message", v1_namespace_condition->message) == NULL) {
    goto fail; //String
    }
     } 


    // v1_namespace_condition->reason
    if(v1_namespace_condition->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1_namespace_condition->reason) == NULL) {
    goto fail; //String
    }
     } 


    // v1_namespace_condition->status
    if (!v1_namespace_condition->status) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "status", v1_namespace_condition->status) == NULL) {
    goto fail; //String
    }


    // v1_namespace_condition->type
    
    if(cJSON_AddStringToObject(item, "type", typev1_namespace_condition_ToString(v1_namespace_condition->type)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_namespace_condition_t *v1_namespace_condition_parseFromJSON(cJSON *v1_namespace_conditionJSON){

    v1_namespace_condition_t *v1_namespace_condition_local_var = NULL;

    // v1_namespace_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(v1_namespace_conditionJSON, "lastTransitionTime");
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1_namespace_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_namespace_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1_namespace_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_namespace_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1_namespace_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_namespace_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1_namespace_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_namespace_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    kubernetes_v1_namespace_condition_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = typev1_namespace_condition_FromString(type->valuestring);


    v1_namespace_condition_local_var = v1_namespace_condition_create (
        last_transition_time ? strdup(last_transition_time->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        typeVariable
        );

    return v1_namespace_condition_local_var;
end:
    return NULL;

}
