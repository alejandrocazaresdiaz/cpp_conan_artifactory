#include <string>
#include <CUnit/Basic.h>
#include "../impFromJfrogLib.h"

using namespace std;

int init_suite1(void){
   return 0;
}

int clean_suite1(void){
   return 0;
}

void testREAD_JSON(void){
    if (1==1) {
      CU_ASSERT(0 == 0 );
   }
}
void testX1(void){
    CU_ASSERT(1 == 1 );
    CU_ASSERT(2 == 2 );
    CU_ASSERT(3 == 3 );
    CU_ASSERT(4 == 7 );
    CU_ASSERT(5 == 5 );
}
void testSetFileName(void){
    CU_ASSERT(0 == setFileName("my_config.json") );
}
void testGETSTRING(void){
    CU_ASSERT("POC Conan - Hello World" == readJson() );
}
void testTypeOfJSONCorrect(){
    CU_ASSERT("NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE"==string(typeid(readJson()).name()) );
}
void testGETNUMBER(void){
    CU_ASSERT(7 == getNumber());
}

int main(){
    CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

    /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_ConanDemo", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* NOTE - ORDER IS IMPORTANT - */
   if (
    (NULL == CU_add_test(pSuite, "Demo ot CUnit in a Conan project, testSetFileName()", testSetFileName))
    || (NULL == CU_add_test(pSuite, "Demo - Conan project with CUnit, testREAD_JSON()", testREAD_JSON))
    || (NULL == CU_add_test(pSuite, "Demo - Conan project with CUnit, testGETSTRING()", testGETSTRING))
    || (NULL == CU_add_test(pSuite, "Demo - Conan project with CUnit, testTypeOfJSONCorrect()", testTypeOfJSONCorrect))
    || (NULL == CU_add_test(pSuite, "Demo - Conan project with CUnit, testGETNUMBER", testGETNUMBER))
    ) {
          CU_cleanup_registry();
          return CU_get_error();
       }


    /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}