CC=ccsc
PK2=pk2cmd

DEVICE=PIC18F4550
UNIT1=VoltUSB
UNIT1_FILE=voltimetro_usb

HFLAGS=+FH +LN -T -A -M -Z +DF +Y=9 +STDOUT +EA
BFLAGS=+FB +LN -T -A -M -Z +DF +Y=9 +STDOUT +EA
MFLAGS=+FM +LN -T -A -M -Z +DF +Y=9 +STDOUT +EA

PK2FLAGS=-E -P$(DEVICE) -M -R -J -F

all: $(UNIT1)

$(UNIT1): $(UNIT1_FILE).c
	$(CC) $(HFLAGS) $(UNIT1_FILE).c
	
Burn:
	$(PK2) $(PK2FLAGS) $(UNIT1_FILE).hex

clean:
	rm *.cof *.err *.esym *.hex *.lst *.pjt *.STA *.sym *.tre *.MCP *.PWI *.DBK