/*
 * kmemdump.c -- copy a range of the running kernel's memory to a file,
 * read-only.  OPENSTEP 4.2 i386 target tool; built on the target with cc.
 *
 *     kmemdump <hex-address> <hex-length> <output-file>
 *
 * Opens /dev/kmem O_RDONLY and copies [address, address+length) to the
 * output file in 4096-byte reads.  It writes nothing to the kernel and
 * decides nothing: the host compares the result with the original
 * mach_kernel bytes.
 *
 * Safety window.  Only the range of the kernel image as laid out by the
 * original Mach-O load commands (mk-183.34.4 RELEASE_I386, SHA-256
 * 33469393...) is accepted: __TEXT 0x100000 .. end of __OBJC 0x20a000.
 * Every page there is part of the loaded image, so no read can touch an
 * unmapped address.  Anything outside is refused before /dev/kmem is
 * opened.  __LINKEDIT (0x780000) is deliberately outside the window.
 *
 * That a /dev/kmem offset equals a kernel virtual address on this kernel
 * is not assumed by this program; the host proves it on every run by
 * comparing the dumped __TEXT with the file bytes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libc.h>      /* NeXT: declares open/read/lseek/fsync; unistd.h does not */

#define WINDOW_LO 0x00100000UL
#define WINDOW_HI 0x0020a000UL
#define CHUNK     4096

int main(argc, argv)
    int    argc;
    char **argv;
{
    unsigned long  addr, len, done;
    int            in, out, want, got;
    unsigned char  buf[CHUNK];

    if (argc != 4) {
        fprintf(stderr, "usage: kmemdump <hex-address> <hex-length> <out>\n");
        return 2;
    }
    addr = strtoul(argv[1], (char **)0, 16);
    len  = strtoul(argv[2], (char **)0, 16);
    if (len == 0 || addr < WINDOW_LO || addr > WINDOW_HI
        || len > WINDOW_HI - addr) {
        fprintf(stderr, "kmemdump: 0x%lx+0x%lx outside 0x%lx..0x%lx, refused\n",
                addr, len, WINDOW_LO, WINDOW_HI);
        return 2;
    }
    in = open("/dev/kmem", O_RDONLY);
    if (in < 0) {
        fprintf(stderr, "kmemdump: open /dev/kmem: %s\n", strerror(errno));
        return 1;
    }
    out = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) {
        fprintf(stderr, "kmemdump: open %s: %s\n", argv[3], strerror(errno));
        close(in);
        return 1;
    }
    if (lseek(in, (long)addr, 0) != (long)addr) {
        fprintf(stderr, "kmemdump: lseek 0x%lx: %s\n", addr, strerror(errno));
        close(in); close(out);
        return 1;
    }
    done = 0;
    while (done < len) {
        want = (len - done) > CHUNK ? CHUNK : (int)(len - done);
        got = read(in, buf, want);
        if (got != want) {
            fprintf(stderr, "kmemdump: read at 0x%lx: got %d of %d: %s\n",
                    addr + done, got, want,
                    got < 0 ? strerror(errno) : "short read");
            break;
        }
        if (write(out, buf, got) != got) {
            fprintf(stderr, "kmemdump: write %s: %s\n", argv[3], strerror(errno));
            break;
        }
        done += got;
    }
    close(in);
    if (fsync(out) != 0)
        fprintf(stderr, "kmemdump: fsync %s: %s\n", argv[3], strerror(errno));
    close(out);
    printf("KMEMDUMP addr=%08lx len=%08lx done=%08lx %s\n",
           addr, len, done, done == len ? "OK" : "INCOMPLETE");
    return done == len ? 0 : 1;
}
