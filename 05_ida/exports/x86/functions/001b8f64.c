/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8f64. */
unsigned int __cdecl -[AudioStream mixBuffer:maxCount:rate:format:channelCount:descriptor:virgin:streamCount:](
        AudioStream *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5,
        int *a6,
        unsigned int *a7,
        $2D87D4CA0FCCD4E0D80DDC4A8D8F85EA *a8,
        char a9,
        unsigned int a10)
{
  unsigned int v10; // esi
  queue_entry *next; // ebx
  unsigned int v13; // [esp+Ch] [ebp-8h]

  v10 = 0; /*0x1b8f76*/
  if ( self->isPaused ) /*0x1b8f78*/
    return 0; /*0x1b8f7e*/
  objc_msgSend(self->regionQueueLock, sel_lock); /*0x1b8f93*/
  next = self->regionQueue.next; /*0x1b8f9b*/
  if ( &self->regionQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1b8fa3*/
  {
    objc_msgSend(self->regionQueueLock, sel_unlock); /*0x1b8fb0*/
    return 0; /*0x1b8fb5*/
  }
  else
  {
    do /*0x1b9099*/
    {
      if ( *((_DWORD *)next + 2) < *((_DWORD *)next + 1) && !*((_DWORD *)next + 13) ) /*0x1b8fc8*/
      {
        if ( !*a5 ) /*0x1b8fd5*/
          *a5 = self->samplingRate; /*0x1b8fdd*/
        if ( *a6 == -1 ) /*0x1b8fe5*/
          *a6 = self->dataFormat; /*0x1b8fea*/
        if ( !*a7 ) /*0x1b8fef*/
          *a7 = self->channelCount; /*0x1b8ff7*/
        if ( -[AudioStream canConvertRegion:rate:format:channelCount:]( /*0x1b9014*/
               self,
               sel_canConvertRegion_rate_format_channelCount_,
               next,
               *a5,
               *a6,
               *a7) )
        {
          v13 = -[AudioStream mixRegion:descriptor:buffer:maxCount:virgin:rate:format:channelCount:]( /*0x1b9055*/
                  self,
                  sel_mixRegion_descriptor_buffer_maxCount_virgin_rate_format_channelCount_,
                  next,
                  a8,
                  v10 + a3,
                  a4 - v10,
                  a9,
                  *a5,
                  *a6,
                  *a7);
          if ( !*((_DWORD *)next + 10) ) /*0x1b905b*/
          {
            *((_DWORD *)next + 8) = a8; /*0x1b9064*/
            *((_DWORD *)next + 10) = 1; /*0x1b9067*/
          }
          if ( *((_DWORD *)next + 2) >= *((_DWORD *)next + 1) && !*((_DWORD *)next + 11) ) /*0x1b9076*/
          {
            *((_DWORD *)next + 9) = a8; /*0x1b907f*/
            *((_DWORD *)next + 11) = 1; /*0x1b9082*/
          }
          v10 += v13; /*0x1b9089*/
          if ( a4 <= v10 ) /*0x1b908f*/
            break; /*0x1b908f*/
        }
      }
      next = *((queue_entry **)next + 15); /*0x1b9091*/
    }
    while ( &self->regionQueue != ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ); /*0x1b9099*/
    objc_msgSend(self->regionQueueLock, sel_unlock); /*0x1b90aa*/
    if ( a9 ) /*0x1b90b6*/
    {
      if ( a4 > v10 ) /*0x1b90bb*/
        -[AudioStream clearForMix:size:format:](self, sel_clearForMix_size_format_, v10 + a3, a4 - v10, *a6); /*0x1b90d7*/
    }
    return v10; /*0x1b90dc*/
  }
}
