# Make the UEFI bootloader

EFIINCDIR=$$EFIDIR/inc/
CFLAGS=-I$$EFIINCDIR\
		  -fpic\
		  -ffreestanding\
		  -fno-stack-protector\
		  -fno-stack-check\
		  -fshort-wchar\
		  -mno-red-zone\
		  -maccumulate-outgoing-args

EFILDFLAGS=-shared\
		   -Bsymbolic\
		   -L$$EFIINCDIR/x86_64/lib\
		   -L$$EFIINCDIR/x86_64/gnuefi\
		   -T$$EFIINCDIR/gnuefi/elf_x86_64_efi.lds\
		   $$EFIINCDIR/x86_64/gnuefi/crt0-efi-x86_64.o


OUTDIR=./out/
.PHONY: out all setup clean

clean: $(OUTDIR)
	rm -rf $(OUTDIR)

all: $(OUTDIR)boot.efi

$(OUTDIR):
	mkdir $@

$(OUTDIR)efi_boot.o: $(OUTDIR) efi_boot.c
	$$CC  $(CFLAGS) -c $(word 2,$^) -o $@

$(OUTDIR)efi_boot.so: $(OUTDIR) $(OUTDIR)efi_boot.o
	$$LD  $(word 2,$^) $(EFILDFLAGS) -o $@


$(OUTDIR)boot.efi: $(OUTDIR) $(OUTDIR)efi_boot.so
	$$OBJCPY $(OBJFLAGS) $(word 2, $^) -o $@

