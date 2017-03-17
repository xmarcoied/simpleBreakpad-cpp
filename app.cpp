#include "client/linux/handler/exception_handler.h"
static bool dumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
void* context, bool succeeded) {
  printf("Dump path: %s\n", descriptor.path());
  return succeeded;
}

void buggy_function(){
	volatile int* a = (int*)(NULL); *a = 1; 
}


int main(int argc, char* argv[]) {
  google_breakpad::MinidumpDescriptor descriptor("./dumps");
  google_breakpad::ExceptionHandler eh(descriptor, NULL, dumpCallback, NULL, true, -1);
  buggy_function();
  return 0;
}
