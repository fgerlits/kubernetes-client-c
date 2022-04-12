#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_hpa_scaling_policy.h"



v2_hpa_scaling_policy_t *v2_hpa_scaling_policy_create(
    int period_seconds,
    char *type,
    int value
    ) {
    v2_hpa_scaling_policy_t *v2_hpa_scaling_policy_local_var = malloc(sizeof(v2_hpa_scaling_policy_t));
    if (!v2_hpa_scaling_policy_local_var) {
        return NULL;
    }
    v2_hpa_scaling_policy_local_var->period_seconds = period_seconds;
    v2_hpa_scaling_policy_local_var->type = type;
    v2_hpa_scaling_policy_local_var->value = value;

    return v2_hpa_scaling_policy_local_var;
}


void v2_hpa_scaling_policy_free(v2_hpa_scaling_policy_t *v2_hpa_scaling_policy) {
    if(NULL == v2_hpa_scaling_policy){
        return ;
    }
    listEntry_t *listEntry;
    if (v2_hpa_scaling_policy->type) {
        free(v2_hpa_scaling_policy->type);
        v2_hpa_scaling_policy->type = NULL;
    }
    free(v2_hpa_scaling_policy);
}

cJSON *v2_hpa_scaling_policy_convertToJSON(v2_hpa_scaling_policy_t *v2_hpa_scaling_policy) {
    cJSON *item = cJSON_CreateObject();

    // v2_hpa_scaling_policy->period_seconds
    if (!v2_hpa_scaling_policy->period_seconds) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "periodSeconds", v2_hpa_scaling_policy->period_seconds) == NULL) {
    goto fail; //Numeric
    }


    // v2_hpa_scaling_policy->type
    if (!v2_hpa_scaling_policy->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v2_hpa_scaling_policy->type) == NULL) {
    goto fail; //String
    }


    // v2_hpa_scaling_policy->value
    if (!v2_hpa_scaling_policy->value) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "value", v2_hpa_scaling_policy->value) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2_hpa_scaling_policy_t *v2_hpa_scaling_policy_parseFromJSON(cJSON *v2_hpa_scaling_policyJSON){

    v2_hpa_scaling_policy_t *v2_hpa_scaling_policy_local_var = NULL;

    // v2_hpa_scaling_policy->period_seconds
    cJSON *period_seconds = cJSON_GetObjectItemCaseSensitive(v2_hpa_scaling_policyJSON, "periodSeconds");
    if (!period_seconds) {
        goto end;
    }

    
    if(!cJSON_IsNumber(period_seconds))
    {
    goto end; //Numeric
    }

    // v2_hpa_scaling_policy->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v2_hpa_scaling_policyJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // v2_hpa_scaling_policy->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v2_hpa_scaling_policyJSON, "value");
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }


    v2_hpa_scaling_policy_local_var = v2_hpa_scaling_policy_create (
        period_seconds->valuedouble,
        strdup(type->valuestring),
        value->valuedouble
        );

    return v2_hpa_scaling_policy_local_var;
end:
    return NULL;

}
