/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ae510. */
int __cdecl -[SCSIDisk setupScsiReq:scsiReq:](
        SCSIDisk *self,
        int a2,
        $BB0ECD142E749ABD0946980FC80D177E *a3,
        $71639E5036F17B36840F09F8ED9B0E88 *a4)
{
  unsigned int v4; // esi
  $8EF4127CF77ECA3DDB612FCF233DC3A8 *var5; // esi

  v4 = -[IODisk blockSize](self, sel_blockSize); /*0x1ae52c*/
  bzero(a4, 0x54u); /*0x1ae531*/
  *(_BYTE *)a4 = self->_target; /*0x1ae53f*/
  *((_BYTE *)a4 + 1) = self->_lun; /*0x1ae54a*/
  if ( a3->var0 == 1 ) /*0x1ae555*/
  {
    *((_BYTE *)a4 + 14) = 0; /*0x1ae574*/
    -[SCSIDisk genRwCdb:readFlag:block:blockCnt:]( /*0x1ae591*/
      self,
      sel_genRwCdb_readFlag_block_blockCnt_,
      (char *)a4 + 2,
      0,
      a3->var1,
      a3->var2);
    goto LABEL_7; /*0x1ae591*/
  }
  if ( !a3->var0 ) /*0x1ae557*/
  {
    *((_BYTE *)a4 + 14) = 1; /*0x1ae564*/
    -[SCSIDisk genRwCdb:readFlag:block:blockCnt:]( /*0x1ae572*/
      self,
      sel_genRwCdb_readFlag_block_blockCnt_,
      (char *)a4 + 2,
      1,
      a3->var1,
      a3->var2);
LABEL_7:
    a3->var5 = nullptr; /*0x1ae596*/
    *((_DWORD *)a4 + 4) = a3->var2 * v4; /*0x1ae5a1*/
    *((_DWORD *)a4 + 5) = 30; /*0x1ae5a4*/
    *((_BYTE *)a4 + 24) |= 1u; /*0x1ae5ab*/
    return 0; /*0x1ae5af*/
  }
  if ( a3->var0 <= 4u ) /*0x1ae55c*/
  {
    var5 = a3->var5; /*0x1ae5b4*/
    if ( *(_WORD *)var5 != *(_WORD *)&self->_target ) /*0x1ae5c4*/
    {
      *((_DWORD *)var5 + 7) = 7; /*0x1ae5c6*/
      a3->var11 = -706; /*0x1ae5cd*/
      -[SCSIDisk sdIoComplete:](self, sel_sdIoComplete_, a3); /*0x1ae5e0*/
      return 7; /*0x1ae5ea*/
    }
    qmemcpy(a4, var5, 0x54u); /*0x1ae5f2*/
  }
  return 0; /*0x1ae5f9*/
}
