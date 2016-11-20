################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ice\ Climber.cpp 

OBJS += \
./src/Ice\ Climber.o 

CPP_DEPS += \
./src/Ice\ Climber.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ice\ Climber.o: ../src/Ice\ Climber.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Ice Climber.d" -MT"src/Ice\ Climber.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


