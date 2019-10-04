################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/biblioteca_operaciones_matematicas.c \
../src/tp_laboratorio_1.c 

OBJS += \
./src/biblioteca_operaciones_matematicas.o \
./src/tp_laboratorio_1.o 

C_DEPS += \
./src/biblioteca_operaciones_matematicas.d \
./src/tp_laboratorio_1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


