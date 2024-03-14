#include "level_zero/ze_api.h"
#include <iostream>

void logerror(ze_result_t err) {
	ze_driver_handle_t driver[1];
	uint count = 1;
	ze_result_t res = zeDriverGet(&count, driver);
	if (res != ZE_RESULT_SUCCESS) return;
	if (count > 1) return;
	
	std::cout << "Error code ";
	switch(err) {
		case ZE_RESULT_SUCCESS:
			std::cout << "ZE_RESULT_SUCCESS"; break;
		default:
			std::cout << err; break;
	}
	
	const char *msg = "Test";
	zeDriverGetLastErrorDescription(driver[0], &msg);
	std::cout <<": " << msg << std::endl;
	return;
}

#define VALIDATECALL(myZeCall) \
    if (myZeCall != ZE_RESULT_SUCCESS){ \
        std::cout << "Error at "       \
            << #myZeCall << ": "       \
            << __FUNCTION__ << ": "    \
            << __LINE__ << std::endl;  \
        logerror(myZeCall); \
        exit(1); \
    }


int main() {
	ze_result_t res;
	
	res = zeInit(0);
	
	uint count = 5;
	ze_driver_handle_t driver[5];
	VALIDATECALL(zeDriverGet(&count, driver));
	std::cout << "Available drivers: " << count << std::endl;
	for(uint i = 0; i < count; i++) {
		std::cout << "Driver " << i << " - ";
		uint count = 5;
		VALIDATECALL(zeDeviceGet(driver[i], &count, NULL));
		std::cout << count << " Devices:" << std::endl;
		
		ze_device_handle_t devices[5];
		VALIDATECALL(zeDeviceGet(driver[i], &count, devices));
		
		for(uint j = 0; j < count; j++) {
			ze_device_properties_t props;
			VALIDATECALL(zeDeviceGetProperties(devices[j], &props));
			std::cout << "\t" << props.name << std::endl;
		}
	}
	return 0;
}
