################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SolutionParent.cpp \
../driver.cpp \
../peakValue.cpp \
../reverseLinkedinList.cpp 

OBJS += \
./SolutionParent.o \
./driver.o \
./peakValue.o \
./reverseLinkedinList.o 

CPP_DEPS += \
./SolutionParent.d \
./driver.d \
./peakValue.d \
./reverseLinkedinList.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


