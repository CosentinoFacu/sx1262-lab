CLI = arduino-cli

PORT ?= /dev/ttyACM0
FQBN ?= esp32:esp32:XIAO_ESP32S3
BAUD ?= 115200

SRC_DIR = firmware/src

TMP = build/arduino
SKETCH = $(TMP)/main


.PHONY: prepare compile upload monitor clean

all: info prepare compile upload clean monitor

info:
	@echo "=== Configuración ==="
	@echo "PORT=$(PORT)"
	@echo "FQBN=$(FQBN)"
	@echo "BAUD=$(BAUD)"

prepare:
	@echo "=== Preparando sketch temporal ==="
	@rm -rf $(SKETCH)
	@mkdir -p $(SKETCH)
	@find firmware/src -name "*.ino" -exec cp {} $(SKETCH) \;
	@find firmware/src -name "*.cpp" -exec cp {} $(SKETCH) \;
	@find firmware/src -name "*.h"   -exec cp {} $(SKETCH) \;
	@find board -name "*.h"   -exec cp {} $(SKETCH) \;
	@echo "Ready"

compile:
	@echo "=== Compilando ==="
	$(CLI) compile \
	--fqbn $(FQBN) \
	$(SKETCH)


upload:
	@echo "=== Cargando firmware ==="
	$(CLI) upload \
	-p $(PORT) \
	--fqbn $(FQBN) \
	$(SKETCH)

monitor:
	@echo "=== Monitor serie ==="
	$(CLI) monitor \
	-p $(PORT) \
	-c baudrate=$(BAUD)

clean: 
	rm -rf build