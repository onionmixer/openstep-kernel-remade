
int _pmap_pte_valid(int param_1,uint param_2)

{
  return ((*(uint *)(((*(uint *)(*(int *)(param_1 + 8) +
                                ((_m68k_pt1_mask & param_2) >> (_m68k_pt1_shift & 0x3f)) * 4) >> 9)
                     << (_m68k_pt1_l2ptr & 0x3f)) +
                    ((_m68k_pt2_mask & param_2) >> (_m68k_pt2_shift & 0x3f)) * 4) >> 7) <<
         (_m68k_pt2_l3ptr & 0x3f)) + ((_m68k_pte_mask & param_2) >> (_m68k_pte_shift & 0x3f)) * 4;
}

