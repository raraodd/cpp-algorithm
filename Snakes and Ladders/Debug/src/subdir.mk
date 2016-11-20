################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Snakes\ and\ Ladders.cpp 

OBJS += \
./src/Snakes\ and\ Ladders.o 

CPP_DEPS += \
./src/Snakes\ and\ Ladders.d 


# Each subdirectory must supply rules for building sources it contributes
src/Snakes\ and\ Ladders.o: ../src/Snakes\ and\ Ladders.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Snakes and Ladders.d" -MT"src/Snakes\ and\ Ladders.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


