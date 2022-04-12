#ifndef v1beta2_limited_priority_level_configuration_TEST
#define v1beta2_limited_priority_level_configuration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_limited_priority_level_configuration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_limited_priority_level_configuration.h"
v1beta2_limited_priority_level_configuration_t* instantiate_v1beta2_limited_priority_level_configuration(int include_optional);

#include "test_v1beta2_limit_response.c"


v1beta2_limited_priority_level_configuration_t* instantiate_v1beta2_limited_priority_level_configuration(int include_optional) {
  v1beta2_limited_priority_level_configuration_t* v1beta2_limited_priority_level_configuration = NULL;
  if (include_optional) {
    v1beta2_limited_priority_level_configuration = v1beta2_limited_priority_level_configuration_create(
      56,
       // false, not to have infinite recursion
      instantiate_v1beta2_limit_response(0)
    );
  } else {
    v1beta2_limited_priority_level_configuration = v1beta2_limited_priority_level_configuration_create(
      56,
      NULL
    );
  }

  return v1beta2_limited_priority_level_configuration;
}


#ifdef v1beta2_limited_priority_level_configuration_MAIN

void test_v1beta2_limited_priority_level_configuration(int include_optional) {
    v1beta2_limited_priority_level_configuration_t* v1beta2_limited_priority_level_configuration_1 = instantiate_v1beta2_limited_priority_level_configuration(include_optional);

	cJSON* jsonv1beta2_limited_priority_level_configuration_1 = v1beta2_limited_priority_level_configuration_convertToJSON(v1beta2_limited_priority_level_configuration_1);
	printf("v1beta2_limited_priority_level_configuration :\n%s\n", cJSON_Print(jsonv1beta2_limited_priority_level_configuration_1));
	v1beta2_limited_priority_level_configuration_t* v1beta2_limited_priority_level_configuration_2 = v1beta2_limited_priority_level_configuration_parseFromJSON(jsonv1beta2_limited_priority_level_configuration_1);
	cJSON* jsonv1beta2_limited_priority_level_configuration_2 = v1beta2_limited_priority_level_configuration_convertToJSON(v1beta2_limited_priority_level_configuration_2);
	printf("repeating v1beta2_limited_priority_level_configuration:\n%s\n", cJSON_Print(jsonv1beta2_limited_priority_level_configuration_2));
}

int main() {
  test_v1beta2_limited_priority_level_configuration(1);
  test_v1beta2_limited_priority_level_configuration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_limited_priority_level_configuration_MAIN
#endif // v1beta2_limited_priority_level_configuration_TEST
