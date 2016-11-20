################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Falling\ Ball.cpp 

OBJS += \
./src/Falling\ Ball.o 

CPP_DEPS += \
./src/Falling\ Ball.d 


# Each subdirectory must supply rules for building sources it contributes
src/Falling\ Ball.o: ../src/Falling\ Ball.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Falling Ball.d" -MT"src/Falling\ Ball.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


