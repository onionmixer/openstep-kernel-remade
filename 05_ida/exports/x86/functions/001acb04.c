/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1acb04. */
id __cdecl -[SCSIDisk sdCdbWrite:buffer:client:](
        SCSIDisk *self,
        int a2,
        $8EF4127CF77ECA3DDB612FCF233DC3A8 *a3,
        void *a4,
        int a5)
{
  $BB0ECD142E749ABD0946980FC80D177E *v5; // eax
  id v6; // esi
  $BB0ECD142E749ABD0946980FC80D177E *v8; // [esp+Ch] [ebp-4h]

  v5 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, 0); /*0x1acb23*/
  v5->var0 = 3; /*0x1acb2a*/
  v5->var5 = a3; /*0x1acb30*/
  v5->var3 = a4; /*0x1acb33*/
  v5->var4 = a5; /*0x1acb36*/
  v5->var6 = nullptr; /*0x1acb39*/
  *((_BYTE *)v5 + 32) &= ~1u; /*0x1acb40*/
  v8 = v5; /*0x1acb50*/
  v6 = -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v5); /*0x1acb58*/
  -[SCSIDisk freeSdBuf:](self, sel_freeSdBuf_, v8); /*0x1acb69*/
  return v6; /*0x1acb73*/
}
