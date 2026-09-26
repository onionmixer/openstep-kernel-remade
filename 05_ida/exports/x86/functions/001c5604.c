/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c5604. */
void __cdecl -[IOSVGADisplay _VGARemoveCursor:shmem:](
        IOSVGADisplay *self,
        SEL a2,
        $514E7C50D28E54AB164B6500F83867A3 *a3,
        $E63760587FADDAA675F803BB3FBE6402 *a4)
{
  unsigned int v4; // esi
  _DWORD *v5; // edi
  int v6; // [esp+1Ch] [ebp-3Ch]
  int v7; // [esp+20h] [ebp-38h]
  int v8; // [esp+24h] [ebp-34h]
  unsigned int v9; // [esp+28h] [ebp-30h]
  int v10; // [esp+2Ch] [ebp-2Ch]
  int v11; // [esp+34h] [ebp-24h]
  int v12; // [esp+38h] [ebp-20h]
  int v13; // [esp+3Ch] [ebp-1Ch]
  int v14; // [esp+40h] [ebp-18h]
  int v15; // [esp+44h] [ebp-14h]
  int v16; // [esp+48h] [ebp-10h]
  int v17; // [esp+4Ch] [ebp-Ch]

  v17 = 0; /*0x1c560d*/
  v16 = 0; /*0x1c5614*/
  v14 = *((_DWORD *)a4 + 12); /*0x1c5621*/
  v15 = *((_DWORD *)a4 + 13); /*0x1c5627*/
  v12 = *((_DWORD *)a4 + 3); /*0x1c562d*/
  v13 = *((_DWORD *)a4 + 4); /*0x1c5633*/
  -[IOSVGADisplay savePlaneAndSegmentSettings](self, sel_savePlaneAndSegmentSettings); /*0x1c5640*/
  v10 = a3->var0 >> 4; /*0x1c5664*/
  v4 = (__int16)v13 - (__int16)v15; /*0x1c5671*/
  v9 = 0x10000 / (a3->var0 >> 3); /*0x1c568b*/
  v11 = 2 * (((__int16)v12 - (__int16)v14) >> 4) + 2 * v4 % v9 * v10 + 655360; /*0x1c56a9*/
  v8 = v4 / v9; /*0x1c56ac*/
  v7 = v9 * (v4 / v9 + 1); /*0x1c56b6*/
  -[IOSVGADisplay setWriteSegment:](self, sel_setWriteSegment_, (unsigned __int8)(v4 / v9)); /*0x1c56cb*/
  -[IOSVGADisplay setReadSegment:](self, sel_setReadSegment_, (unsigned __int8)(v4 / v9)); /*0x1c56df*/
  v6 = 2 * (*((_WORD *)a4 + 16) & 0xF); /*0x1c56f0*/
  v5 = (_DWORD *)((char *)a4 + 584); /*0x1c56f5*/
  if ( (__int16)v12 >= (__int16)v14 ) /*0x1c5714*/
    v17 = dword_1E53D8[*((__int16 *)a4 + 20) - (__int16)v12]; /*0x1c5724*/
  if ( SHIWORD(v12) <= SHIWORD(v14) ) /*0x1c5746*/
    v16 = ~dword_1E53D8[16 - ((v12 >> 16) - *((__int16 *)a4 + 21))]; /*0x1c5769*/
  while ( (v13 >> 16) - (__int16)v15 > (int)v4 ) /*0x1c5899*/
  {
    if ( v7 == v4 ) /*0x1c5777*/
    {
      v11 = 2 * v10 * (v4 % v9) + 655360 + 2 * (((__int16)v12 - (__int16)v14) >> 4); /*0x1c5791*/
      ++v8; /*0x1c5794*/
      v7 = v4 + v9; /*0x1c579c*/
      -[IOSVGADisplay setWriteSegment:](self, sel_setWriteSegment_, (unsigned __int8)v8); /*0x1c57b1*/
      -[IOSVGADisplay setReadSegment:](self, sel_setReadSegment_, (unsigned __int8)v8); /*0x1c57c5*/
    }
    if ( (__int16)v12 >= (__int16)v14 ) /*0x1c57d1*/
    {
      -[IOSVGADisplay _readBpp4planar:toBpp2packed32:](self, sel__readBpp4planar_toBpp2packed32_, v11, &dword_1E8734); /*0x1c57e6*/
      dword_1E8734 = *v5++ & v17 | dword_1E8734 & ~v17; /*0x1c57fd*/
      -[IOSVGADisplay _writeBpp2packed32:toBpp4planar:](self, sel__writeBpp2packed32_toBpp4planar_, &dword_1E8734, v11); /*0x1c581a*/
    }
    if ( SHIWORD(v12) <= SHIWORD(v14) ) /*0x1c5826*/
    {
      if ( v6 ) /*0x1c582c*/
      {
        -[IOSVGADisplay _readBpp4planar:toBpp2packed32:]( /*0x1c584d*/
          self,
          sel__readBpp4planar_toBpp2packed32_,
          v11 + 2,
          &dword_1E8738);
        dword_1E8738 = *v5++ & v16 | dword_1E8738 & ~v16; /*0x1c5864*/
        -[IOSVGADisplay _writeBpp2packed32:toBpp4planar:]( /*0x1c5881*/
          self,
          sel__writeBpp2packed32_toBpp4planar_,
          &dword_1E8738,
          v11 + 2);
      }
      else
      {
        ++v5; /*0x1c582e*/
      }
    }
    v11 += 2 * v10; /*0x1c5892*/
    ++v4; /*0x1c5895*/
  }
  -[IOSVGADisplay restorePlaneAndSegmentSettings](self, sel_restorePlaneAndSegmentSettings); /*0x1c58aa*/
}
