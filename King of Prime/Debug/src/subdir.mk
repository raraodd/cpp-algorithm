################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/King\ of\ Prime.cpp 

OBJS += \
./src/King\ of\ Prime.o 

CPP_DEPS += \
./src/King\ of\ Prime.d 


# Each subdirectory must supply rules for building sources it contributes
src/King\ of\ Prime.o: ../src/King\ of\ Prime.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/King of Prime.d" -MT"src/King\ of\ Prime.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


