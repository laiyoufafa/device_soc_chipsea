##########################################################################################################################
# File automatically-generated by tool: [projectgenerator] version: [3.13.0-B3] date: [Fri Apr 30 08:31:16 CST 2021] 
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# ChangeLog :
#	2017-02-10 - Several enhancements + project update mode
#   2015-07-22 - first version
# ------------------------------------------------

######################################
# target
######################################
TARGET = cst85f01


#######################################
# paths
#######################################
# Build path
BUILD_DIR = $(OUT_DIR_PATH)

#######################################
# toolchain paths
#######################################
# Toolchain path
ifneq ($(TOOLCHAIN_DIR_PATH), )
GCC_PATH = $(TOOLCHAIN_DIR_PATH)
endif

#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifneq ($(GCC_PATH), )
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m4

# fpu
FPU = -mfpu=fpv4-sp-d16

# float-abi
#FLOAT-ABI = -mfloat-abi=hard
FLOAT-ABI = -mfloat-abi=softfp
# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = cst85f01.ld

# libraries. remove(-lkernel -larch -lcpup -lexchook -lpm -lutils -lhdf_core -lhdf_osal_lite -lhdf_hcs -lsample_driver)
STATIC_LIB = -lcore -lsec_static -lstartup_boot  -lhandler -lbootstrap 
STATIC_LIB_DIR = -L$(BUILD_DIR)/libs  
LIBS = -lc -lm -lnosys  ./libs/libdrv.a
LIBDIR =
#LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections
LDFLAGS = $(MCU) -specs=nosys.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
$(BUILD_DIR)/$(TARGET).elf: Makefile
	$(CC) $(STATIC_LIB_DIR) -Wl,--whole-archive -Wl,--start-group $(STATIC_LIB) -Wl,--end-group -Wl,--no-whole-archive $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir -p $@

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)

# *** EOF ***
