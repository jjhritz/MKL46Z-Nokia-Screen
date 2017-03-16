################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/frdm_led.c" \
"../Sources/frdm_pushb.c" \
"../Sources/global.c" \
"../Sources/gpio.c" \
"../Sources/int.c" \
"../Sources/main.c" \
"../Sources/nokia_lcd.c" \
"../Sources/pit.c" \
"../Sources/port.c" \
"../Sources/sim.c" \
"../Sources/spi.c" \
"../Sources/systick.c" \
"../Sources/tpm.c" \
"../Sources/tpm_pwm.c" \

C_SRCS += \
../Sources/frdm_led.c \
../Sources/frdm_pushb.c \
../Sources/global.c \
../Sources/gpio.c \
../Sources/int.c \
../Sources/main.c \
../Sources/nokia_lcd.c \
../Sources/pit.c \
../Sources/port.c \
../Sources/sim.c \
../Sources/spi.c \
../Sources/systick.c \
../Sources/tpm.c \
../Sources/tpm_pwm.c \

OBJS += \
./Sources/frdm_led.o \
./Sources/frdm_pushb.o \
./Sources/global.o \
./Sources/gpio.o \
./Sources/int.o \
./Sources/main.o \
./Sources/nokia_lcd.o \
./Sources/pit.o \
./Sources/port.o \
./Sources/sim.o \
./Sources/spi.o \
./Sources/systick.o \
./Sources/tpm.o \
./Sources/tpm_pwm.o \

OBJS_QUOTED += \
"./Sources/frdm_led.o" \
"./Sources/frdm_pushb.o" \
"./Sources/global.o" \
"./Sources/gpio.o" \
"./Sources/int.o" \
"./Sources/main.o" \
"./Sources/nokia_lcd.o" \
"./Sources/pit.o" \
"./Sources/port.o" \
"./Sources/sim.o" \
"./Sources/spi.o" \
"./Sources/systick.o" \
"./Sources/tpm.o" \
"./Sources/tpm_pwm.o" \

C_DEPS += \
./Sources/frdm_led.d \
./Sources/frdm_pushb.d \
./Sources/global.d \
./Sources/gpio.d \
./Sources/int.d \
./Sources/main.d \
./Sources/nokia_lcd.d \
./Sources/pit.d \
./Sources/port.d \
./Sources/sim.d \
./Sources/spi.d \
./Sources/systick.d \
./Sources/tpm.d \
./Sources/tpm_pwm.d \

OBJS_OS_FORMAT += \
./Sources/frdm_led.o \
./Sources/frdm_pushb.o \
./Sources/global.o \
./Sources/gpio.o \
./Sources/int.o \
./Sources/main.o \
./Sources/nokia_lcd.o \
./Sources/pit.o \
./Sources/port.o \
./Sources/sim.o \
./Sources/spi.o \
./Sources/systick.o \
./Sources/tpm.o \
./Sources/tpm_pwm.o \

C_DEPS_QUOTED += \
"./Sources/frdm_led.d" \
"./Sources/frdm_pushb.d" \
"./Sources/global.d" \
"./Sources/gpio.d" \
"./Sources/int.d" \
"./Sources/main.d" \
"./Sources/nokia_lcd.d" \
"./Sources/pit.d" \
"./Sources/port.d" \
"./Sources/sim.d" \
"./Sources/spi.d" \
"./Sources/systick.d" \
"./Sources/tpm.d" \
"./Sources/tpm_pwm.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/frdm_led.o: ../Sources/frdm_led.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/frdm_led.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/frdm_led.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/frdm_pushb.o: ../Sources/frdm_pushb.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/frdm_pushb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/frdm_pushb.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/global.o: ../Sources/global.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/global.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/global.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/gpio.o: ../Sources/gpio.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/gpio.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/gpio.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/int.o: ../Sources/int.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/int.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/int.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/nokia_lcd.o: ../Sources/nokia_lcd.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/nokia_lcd.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/nokia_lcd.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pit.o: ../Sources/pit.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/pit.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/pit.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/port.o: ../Sources/port.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/port.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/port.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sim.o: ../Sources/sim.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sim.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sim.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/spi.o: ../Sources/spi.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/spi.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/spi.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/systick.o: ../Sources/systick.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/systick.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/systick.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/tpm.o: ../Sources/tpm.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/tpm.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/tpm.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/tpm_pwm.o: ../Sources/tpm_pwm.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/tpm_pwm.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/tpm_pwm.o"
	@echo 'Finished building: $<'
	@echo ' '


