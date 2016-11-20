################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/100\ The\ 3N+1\ Problem.cpp 

OBJS += \
./src/100\ The\ 3N+1\ Problem.o 

CPP_DEPS += \
./src/100\ The\ 3N+1\ Problem.d 


# Each subdirectory must supply rules for building sources it contributes
src/100\ The\ 3N+1\ Problem.o: ../src/100\ The\ 3N+1\ Problem.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/100 The 3N+1 Problem.d" -MT"src/100\ The\ 3N+1\ Problem.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


