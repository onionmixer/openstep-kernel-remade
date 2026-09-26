/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bbe60. */
int __cdecl _NXAudioRecordStream(id a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  id v8; // eax
  id v9; // eax
  id v10; // eax

  if ( !a1 ) /*0x1bbe73*/
    return 202; /*0x1bbe75*/
  objc_msgSend(a1, sel_ownerPort); /*0x1bbe88*/
  v8 = objc_msgSend(a1, sel_channel); /*0x1bbe9d*/
  if ( !(unsigned __int8)objc_msgSend(v8, sel_checkOwner_) ) /*0x1bbea6*/
    return 200; /*0x1bbeb2*/
  if ( a2 ) /*0x1bbebe*/
  {
    v9 = objc_msgSend(a1, sel_channel); /*0x1bbf11*/
    v10 = objc_msgSend(v9, sel_audioDevice); /*0x1bbf1a*/
    objc_msgSend(v10, sel__setParameters_toValues_count_forObject_); /*0x1bbf23*/
    if ( (unsigned __int8)objc_msgSend(a1, sel_recordSize_tag_replyTo_replyMsgs_, a2, a3, a6, a7) ) /*0x1bbf3d*/
      return 0; /*0x1bbf50*/
  }
  return 204; /*0x1bbf58*/
}
