/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6284. */
void __cdecl -[IOSVGADisplay _writeBpp2packed32:toBpp4planar:](
        IOSVGADisplay *self,
        SEL a2,
        unsigned int *a3,
        unsigned __int16 *a4)
{
  unsigned int v4; // ecx
  unsigned int v5; // ecx

  -[IOSVGADisplay setWritePlane:](self, sel_setWritePlane_, 1); /*0x1c629d*/
  v4 = HIWORD(*a3); /*0x1c6305*/
  *a4 = (unsigned __int8)~(((*a3 & 0xAA) << 6) /*0x1c636c*/
                         | (8 * (*a3 & 8))
                         | *a3 & 0x20
                         | ((*a3 & 0x80) >> 3)
                         | ((*a3 & 0x200) >> 6)
                         | ((*a3 & 0x800) >> 9)
                         | ((*a3 & 0x2000) >> 12)
                         | ((*a3 & 0x8000) >> 15))
      | ((unsigned __int8)~(((v4 & 0xAA) << 6)
                          | (8 * (v4 & 8))
                          | v4 & 0x20
                          | ((unsigned __int8)(v4 & 0x80) >> 3)
                          | ((unsigned __int16)(HIWORD(*a3) & 0x200) >> 6)
                          | ((unsigned __int16)(HIWORD(*a3) & 0x800) >> 9)
                          | ((unsigned __int16)(HIWORD(*a3) & 0x2000) >> 12)
                          | ((*a3 & 0x80000000) != 0)) << 8);
  -[IOSVGADisplay setWritePlane:](self, sel_setWritePlane_, 0); /*0x1c637c*/
  v5 = HIWORD(*a3); /*0x1c63e4*/
  *a4 = (unsigned __int8)~(((*a3 & 0x55) << 7) /*0x1c6450*/
                         | (16 * (*a3 & 4))
                         | (2 * (*a3 & 0x10))
                         | ((*a3 & 0x40) >> 2)
                         | ((*a3 & 0x100) >> 5)
                         | ((unsigned __int16)(*(_WORD *)a3 & 0x400) >> 8)
                         | ((*a3 & 0x1000) >> 11)
                         | ((*a3 & 0x4000) >> 14))
      | ((unsigned __int8)~(((v5 & 0x55) << 7)
                          | (16 * (v5 & 4))
                          | (2 * (v5 & 0x10))
                          | ((unsigned __int8)(v5 & 0x40) >> 2)
                          | ((unsigned __int16)(v5 & 0x100) >> 5)
                          | ((unsigned __int16)(v5 & 0x400) >> 8)
                          | ((unsigned __int16)(v5 & 0x1000) >> 11)
                          | ((unsigned __int16)(v5 & 0x4000) >> 14)) << 8);
}
