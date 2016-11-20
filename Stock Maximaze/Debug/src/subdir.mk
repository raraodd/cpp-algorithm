################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Stock\ Maximaze.cpp 

OBJS += \
./src/Stock\ Maximaze.o 

CPP_DEPS += \
./src/Stock\ Maximaze.d 


# Each subdirectory must supply rules for building sources it contributes
src/Stock\ Maximaze.o: ../src/Stock\ Maximaze.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Stock Maximaze.d" -MT"src/Stock\ Maximaze.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


