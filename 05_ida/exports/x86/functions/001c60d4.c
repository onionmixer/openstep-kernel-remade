/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c60d4. */
void __cdecl -[IOSVGADisplay _readBpp4planar:toBpp2packed32:](
        IOSVGADisplay *self,
        SEL a2,
        unsigned __int16 *a3,
        unsigned int *a4)
{
  int v4; // ebx

  -[IOSVGADisplay setReadPlane:](self, sel_setReadPlane_, 1); /*0x1c60ea*/
  v4 = (((*(_BYTE *)a3 & 1) == 0) << 15) /*0x1c61a4*/
     | ((~*(_BYTE *)a3 & 2) << 12)
     | ((~*(_BYTE *)a3 & 4) << 9)
     | ((~*(_BYTE *)a3 & 8) << 6)
     | (8 * (~*(_BYTE *)a3 & 0x10))
     | ~*(_BYTE *)a3 & 0x20
     | ((unsigned __int8)(~*(_BYTE *)a3 & 0x40) >> 3)
     | ((unsigned __int8)(~*(_BYTE *)a3 & 0x80) >> 6)
     | ((~*a3 & 0x100) << 23)
     | ((~*a3 & 0x200) << 20)
     | ((~*a3 & 0x400) << 17)
     | ((~*a3 & 0x800) << 14)
     | ((~*a3 & 0x1000) << 11)
     | ((~*a3 & 0x2000) << 8)
     | (32 * (~*a3 & 0x4000))
     | (4 * (~*a3 & 0x8000));
  -[IOSVGADisplay setReadPlane:](self, sel_setReadPlane_, 0); /*0x1c61b3*/
  *a4 = (((*(_BYTE *)a3 & 1) == 0) << 14) /*0x1c6275*/
      | ((~*(_BYTE *)a3 & 2) << 11)
      | ((~*(_BYTE *)a3 & 4) << 8)
      | (32 * (~*(_BYTE *)a3 & 8))
      | (4 * (~*(_BYTE *)a3 & 0x10))
      | ((unsigned __int8)(~*(_BYTE *)a3 & 0x20) >> 1)
      | ((unsigned __int8)(~*(_BYTE *)a3 & 0x40) >> 4)
      | ((unsigned __int8)(~*(_BYTE *)a3 & 0x80) >> 7)
      | ((~*a3 & 0x100) << 22)
      | ((~*a3 & 0x200) << 19)
      | ((~*a3 & 0x400) << 16)
      | ((~*a3 & 0x800) << 13)
      | ((~*a3 & 0x1000) << 10)
      | ((~*a3 & 0x2000) << 7)
      | (16 * (~*a3 & 0x4000))
      | (2 * (~*a3 & 0x8000))
      | v4;
}
