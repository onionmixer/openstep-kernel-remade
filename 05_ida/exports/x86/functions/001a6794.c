/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6794. */
int __cdecl -[IODiskPartition readLabel:](IODiskPartition *self, SEL a2, $8CBD0DAB9EB64966FFA875B94553E7ED *a3)
{
  unsigned int v3; // esi
  id v4; // eax
  int v5; // ebx
  int result; // eax
  unsigned __int8 v7; // al
  int v8; // ebx
  int v9; // edi
  int v10; // esi
  int v11; // eax
  int v12; // ebx
  id v13; // [esp+Ch] [ebp-1Ch]
  int v14; // [esp+10h] [ebp-18h]
  int v15; // [esp+14h] [ebp-14h]
  int v16; // [esp+18h] [ebp-10h]
  unsigned int v17; // [esp+1Ch] [ebp-Ch]
  int v18; // [esp+20h] [ebp-8h]
  int v19; // [esp+24h] [ebp-4h] BYREF

  v18 = 0; /*0x1a679d*/
  v13 = -[IOLogicalDisk physicalDisk](self, sel_physicalDisk); /*0x1a67b4*/
  v3 = -[IOLogicalDisk physicalBlockSize](self, sel_physicalBlockSize); /*0x1a67c7*/
  -[IODevice name](self, sel_name); /*0x1a67d4*/
  v4 = objc_msgSend(v13, sel_isDiskReady_, 1); /*0x1a67e8*/
  v5 = (int)v4; /*0x1a67ed*/
  if ( v4 == (id)-1102 ) /*0x1a67f8*/
    return -1102; /*0x1a6800*/
  if ( v4 )
  {
    -[IODisk stringFromReturn:](self, sel_stringFromReturn_, v4); /*0x1a6818*/
    IOLog("%s readLabel: bogus return from isDiskReady (%s)\n");
    return v5; /*0x1a6829*/
  }
  else
  {
    v7 = (unsigned __int8)objc_msgSend(v13, sel_isFormatted); /*0x1a683b*/
    if ( v3 && v7 ) /*0x1a684c*/
    {
      result = -[IODiskPartition NeXTpartitionOffset](self, sel_NeXTpartitionOffset); /*0x1a6863*/
      v8 = result; /*0x1a6868*/
      if ( result >= 0 ) /*0x1a686f*/
      {
        v17 = (v3 + 7239) / v3; /*0x1a688a*/
        v16 = v17 * v3; /*0x1a6890*/
        v14 = ~page_mask & (page_mask + v17 * v3); /*0x1a68a0*/
        v15 = IOMalloc(v14); /*0x1a68a9*/
        v9 = 0; /*0x1a68ac*/
        v10 = v8; /*0x1a68b1*/
        while ( 1 ) /*0x1a68b4*/
        {
          v11 = IOVmTaskSelf(); /*0x1a68b4*/
          v12 = (int)objc_msgSend(v13, sel_readAt_length_buffer_actualLength_client_, v10, v16, v15, &v19, v11); /*0x1a68d7*/
          if ( !v12 && v19 == v16 && !check_label(v15, v10) ) /*0x1a68ed*/
            break; /*0x1a68ed*/
          if ( v12 != -1102 ) /*0x1a6903*/
          {
            v10 += v17; /*0x1a6905*/
            if ( ++v9 <= 3 ) /*0x1a690c*/
              continue; /*0x1a690c*/
          }
          goto LABEL_18; /*0x1a690c*/
        }
        v18 = 1; /*0x1a6878*/
LABEL_18:
        if ( v18 ) /*0x1a6912*/
        {
          self->_labelValid = 1; /*0x1a6917*/
          get_disk_label(v15, a3); /*0x1a6926*/
          v12 = 0; /*0x1a692b*/
        }
        else if ( v12 != -1102 ) /*0x1a693a*/
        {
          v12 = -1100; /*0x1a693c*/
        }
        IOFree(v15, v14); /*0x1a6949*/
        return v12; /*0x1a694e*/
      }
    }
    else
    {
      return -1101; /*0x1a684e*/
    }
  }
  return result; /*0x1a6953*/
}
