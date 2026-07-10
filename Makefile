CLI = arduino-cli

PORT ?= /dev/ttyACM0
FQBN ?= esp32:esp32:XIAO_ESP32S3
BAUD ?= 115200

SRC_DIR = firmware/src

TMP = temp/arduino
SKETCH = $(TMP)/sx1262_lab


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
	@cp $(SRC_DIR)/* $(SKETCH)/
	@mv $(SKETCH)/main.ino $(SKETCH)/sx1262_lab.ino
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

#monitor:
#	@echo "=== Monitor serie ==="
#	$(CLI) monitor \
#	-p $(PORT) \
#	-c baudrate=$(BAUD)

monitor:
	picocom -b $(BAUD) $(PORT)

clean: 
	rm -rf temp