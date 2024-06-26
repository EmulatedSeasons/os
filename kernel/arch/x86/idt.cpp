#include <stdint.h>
#include <stddef.h>

/* Function prototypes for the ISR functions. IDT[0] to IDT[31] are reserved for hardware exceptions */
extern "C" void isr0();
extern "C" void isr1();
extern "C" void isr2();
extern "C" void isr3();
extern "C" void isr4();
extern "C" void isr5();
extern "C" void isr6();
extern "C" void isr7();
extern "C" void isr8();
extern "C" void isr9();
extern "C" void isr10();
extern "C" void isr11();
extern "C" void isr12();
extern "C" void isr13();
extern "C" void isr14();
extern "C" void isr15();
extern "C" void isr16();
extern "C" void isr17();
extern "C" void isr18();
extern "C" void isr19();
extern "C" void isr20();
extern "C" void isr21();
extern "C" void isr22();
extern "C" void isr23();
extern "C" void isr24();
extern "C" void isr25();
extern "C" void isr26();
extern "C" void isr27();
extern "C" void isr28();
extern "C" void isr29();
extern "C" void isr30();
extern "C" void isr31();
extern "C" void isr32();
extern "C" void isr33();
extern "C" void isr34();
extern "C" void isr35();
extern "C" void isr36();
extern "C" void isr37();
extern "C" void isr38();
extern "C" void isr39();
extern "C" void isr40();
extern "C" void isr41();
extern "C" void isr42();
extern "C" void isr43();
extern "C" void isr44();
extern "C" void isr45();
extern "C" void isr46();
extern "C" void isr47();

struct idt_entry
{
    uint16_t offset_low;
    uint16_t selector;
    uint8_t always0;
    uint8_t type_attributes;
    uint16_t offset_high;
}__attribute__((packed));

struct idtr {
    uint16_t limit;
    uint32_t base;
}__attribute__((packed));

idt_entry idt[256];
idtr idtr;

void idt_new_entry(int num, uint32_t offset, uint16_t sel, uint8_t type_attribs) {
    idt[num].offset_low = (offset & 0xFFFF);
    idt[num].selector = sel;
    idt[num].always0 = 0;
    idt[num].type_attributes = type_attribs;
    idt[num].offset_high = (offset >> 16) & 0xFFFF;
}

extern "C" void idt_setup() {
    idtr.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtr.base = (uint32_t)idt;

    // todo: is there really no other way?
    idt_new_entry(0, (unsigned)isr0, 0x08, 0x8E);
	idt_new_entry(1, (unsigned)isr1, 0x08, 0x8E);
	idt_new_entry(2, (unsigned)isr2, 0x08, 0x8E);
	idt_new_entry(3, (unsigned)isr3, 0x08, 0x8E);
	idt_new_entry(4, (unsigned)isr4, 0x08, 0x8E);
	idt_new_entry(5, (unsigned)isr5, 0x08, 0x8E);
	idt_new_entry(6, (unsigned)isr6, 0x08, 0x8E);
	idt_new_entry(7, (unsigned)isr7, 0x08, 0x8E);
	idt_new_entry(8, (unsigned)isr8, 0x08, 0x8E);
	idt_new_entry(9, (unsigned)isr9, 0x08, 0x8E);
	idt_new_entry(10, (unsigned)isr10, 0x08, 0x8E);
	idt_new_entry(11, (unsigned)isr11, 0x08, 0x8E);
	idt_new_entry(12, (unsigned)isr12, 0x08, 0x8E);
	idt_new_entry(13, (unsigned)isr13, 0x08, 0x8E);
	idt_new_entry(14, (unsigned)isr14, 0x08, 0x8E);
	idt_new_entry(15, (unsigned)isr15, 0x08, 0x8E);
	idt_new_entry(16, (unsigned)isr16, 0x08, 0x8E);
	idt_new_entry(17, (unsigned)isr17, 0x08, 0x8E);
	idt_new_entry(18, (unsigned)isr18, 0x08, 0x8E);
	idt_new_entry(19, (unsigned)isr19, 0x08, 0x8E);
	idt_new_entry(20, (unsigned)isr20, 0x08, 0x8E);
	idt_new_entry(21, (unsigned)isr21, 0x08, 0x8E);
	idt_new_entry(22, (unsigned)isr22, 0x08, 0x8E);
	idt_new_entry(23, (unsigned)isr23, 0x08, 0x8E);
	idt_new_entry(24, (unsigned)isr24, 0x08, 0x8E);
	idt_new_entry(25, (unsigned)isr25, 0x08, 0x8E);
	idt_new_entry(26, (unsigned)isr26, 0x08, 0x8E);
	idt_new_entry(27, (unsigned)isr27, 0x08, 0x8E);
	idt_new_entry(28, (unsigned)isr28, 0x08, 0x8E);
	idt_new_entry(29, (unsigned)isr29, 0x08, 0x8E);
	idt_new_entry(30, (unsigned)isr30, 0x08, 0x8E);
	idt_new_entry(31, (unsigned)isr31, 0x08, 0x8E);
	//PIC entries
	idt_new_entry(32, (unsigned)isr32, 0x08, 0x8E);
	idt_new_entry(33, (unsigned)isr33, 0x08, 0x8E);
	idt_new_entry(34, (unsigned)isr34, 0x08, 0x8E);
	idt_new_entry(35, (unsigned)isr35, 0x08, 0x8E);
	idt_new_entry(36, (unsigned)isr36, 0x08, 0x8E);
	idt_new_entry(37, (unsigned)isr37, 0x08, 0x8E);
	idt_new_entry(38, (unsigned)isr38, 0x08, 0x8E);
	idt_new_entry(39, (unsigned)isr39, 0x08, 0x8E);
	idt_new_entry(40, (unsigned)isr40, 0x08, 0x8E);
	idt_new_entry(41, (unsigned)isr41, 0x08, 0x8E);
	idt_new_entry(42, (unsigned)isr42, 0x08, 0x8E);
	idt_new_entry(43, (unsigned)isr43, 0x08, 0x8E);
	idt_new_entry(44, (unsigned)isr44, 0x08, 0x8E);
	idt_new_entry(45, (unsigned)isr45, 0x08, 0x8E);
	idt_new_entry(46, (unsigned)isr46, 0x08, 0x8E);
	idt_new_entry(47, (unsigned)isr47, 0x08, 0x8E);
}