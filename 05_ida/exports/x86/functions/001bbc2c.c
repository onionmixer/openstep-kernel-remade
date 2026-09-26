/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bbc2c. */
int __cdecl _NXAudioPlayStream(
        id a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12)
{
  id v13; // eax
  int v14; // ebx
  id v15; // eax
  id v16; // eax
  int v17; // eax
  int v18; // eax

  if ( !a1 ) /*0x1bbc43*/
    return 202; /*0x1bbc4a*/
  objc_msgSend(a1, sel_ownerPort); /*0x1bbc58*/
  v13 = objc_msgSend(a1, sel_channel); /*0x1bbc6d*/
  if ( (unsigned __int8)objc_msgSend(v13, sel_checkOwner_) ) /*0x1bbc76*/
  {
    if ( a3 ) /*0x1bbc8e*/
    {
      v15 = objc_msgSend(a1, sel_channel); /*0x1bbd1b*/
      v16 = objc_msgSend(v15, sel_audioDevice); /*0x1bbd24*/
      objc_msgSend(v16, sel__setParameters_toValues_count_forObject_); /*0x1bbd2d*/
      if ( (unsigned __int8)objc_msgSend(a1, sel_playBuffer_size_tag_replyTo_replyMsgs_, a2, a3, a4, a11, a12) ) /*0x1bbd48*/
        return 0; /*0x1bbd56*/
    }
    v14 = 204; /*0x1bbd58*/
  }
  else
  {
    v14 = 200; /*0x1bbc82*/
  }
  v17 = task_self(); /*0x1bbd5f*/
  v18 = vm_deallocate_EXTERNAL(v17, a2, a3); /*0x1bbd65*/
  if ( v18 )
    IOLog((int)"Audio: audio server vm_deallocate error: %s (%d)\n", "MACH ERR", v18);
  return v14; /*0x1bbd89*/
}
