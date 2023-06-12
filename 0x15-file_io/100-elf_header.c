#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <elf.h>

void print_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void print_elf_header(const Elf64_Ehdr *elf_header) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header->e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             ");
    switch (elf_header->e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("  Data:                              ");
    switch (elf_header->e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (elf_header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        default:
            printf("<unknown: %d>\n", elf_header->e_ident[EI_OSABI]);
            break;
    }

    printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (elf_header->e_type) {
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("  Entry point address:               0x%lx\n", elf_header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Error opening file");
    }

    Elf64_Ehdr elf_header;
    ssize_t bytes_read = read(fd, &elf_header, sizeof(elf_header));
    if (bytes_read == -1) {
        print_error("Error reading file");
    }

    if (bytes_read != sizeof(elf_header)) {
        print_error("Invalid ELF file");
    }

    close(fd);

    print_elf_header(&elf_header);

    return 0;
}

