#include "character_zero.c"
#include "character_one.c"
#include "character_two.c"
#include "character_three.c"
#include "character_four.c"
#include "character_five.c"
#include "character_six.c"
#include "character_seven.c"
#include "character_eight.c"
#include "character_nine.c"
#include "character_a.c"
#include "character_b.c"
#include "character_c.c"
#include "character_d.c"
#include "character_e.c"
#include "character_f.c"
#include "character_g.c"
#include "character_h.c"
#include "character_i.c"
#include "character_j.c"
#include "character_k.c"
#include "character_l.c"
#include "character_m.c"
#include "character_n.c"
#include "character_o.c"
#include "character_p.c"
#include "character_q.c"
#include "character_r.c"
#include "character_s.c"
#include "character_t.c"
#include "character_u.c"
#include "character_v.c"
#include "character_w.c"
#include "character_x.c"
#include "character_y.c"
#include "character_z.c"
#include "character_A.c"
#include "character_B.c"
#include "character_C.c"
#include "character_D.c"
#include "character_E.c"
#include "character_F.c"
#include "character_G.c"
#include "character_H.c"
#include "character_I.c"
#include "character_J.c"
#include "character_K.c"
#include "character_L.c"
#include "character_M.c"
#include "character_N.c"
#include "character_O.c"
#include "character_P.c"
#include "character_Q.c"
#include "character_R.c"
#include "character_S.c"
#include "character_T.c"
#include "character_U.c"
#include "character_V.c"
#include "character_W.c"
#include "character_X.c"
#include "character_Y.c"
#include "character_Z.c"
#include "character_exclam.c"
#include "character_at.c"
#include "character_numbersign.c"
#include "character_dollar.c"
#include "character_percent.c"
#include "character_asciicircum.c"
#include "character_ampersand.c"
#include "character_asterisk.c"
#include "character_parenleft.c"
#include "character_parenright.c"
#include "character_hyphen.c"
#include "character_underscore.c"
#include "character_equal.c"
#include "character_plus.c"
#include "character_colon.c"
#include "character_less.c"
#include "character_greater.c"
#include "character_comma.c"
#include "character_period.c"
#include "character_question.c"
#include "character_slash.c"
#include "character_quotedbl.c"
#include "character_braceright.c"
#include "character_braceleft.c"
#include "character_backslash.c"
#include "character_bar.c"
#include "character_asciitilde.c"
#include "character_grave.c"


void load() {
  #ifndef JETBRAINS32_MONO_SET
  #define JETBRAINS32_MONO_SET
  SPACE_PX = 8;
  display_text = display_text32;

  char_map32[48] = &character_zero; 
  char_map32[49] = &character_one; 
  char_map32[50] = &character_two; 
  char_map32[51] = &character_three; 
  char_map32[52] = &character_four; 
  char_map32[53] = &character_five; 
  char_map32[54] = &character_six; 
  char_map32[55] = &character_seven; 
  char_map32[56] = &character_eight; 
  char_map32[57] = &character_nine; 
  char_map32[97] = &character_a; 
  char_map32[98] = &character_b; 
  char_map32[99] = &character_c; 
  char_map32[100] = &character_d; 
  char_map32[101] = &character_e; 
  char_map32[102] = &character_f; 
  char_map32[103] = &character_g; 
  char_map32[104] = &character_h; 
  char_map32[105] = &character_i; 
  char_map32[106] = &character_j; 
  char_map32[107] = &character_k; 
  char_map32[108] = &character_l; 
  char_map32[109] = &character_m; 
  char_map32[110] = &character_n; 
  char_map32[111] = &character_o; 
  char_map32[112] = &character_p; 
  char_map32[113] = &character_q; 
  char_map32[114] = &character_r; 
  char_map32[115] = &character_s; 
  char_map32[116] = &character_t; 
  char_map32[117] = &character_u; 
  char_map32[118] = &character_v; 
  char_map32[119] = &character_w; 
  char_map32[120] = &character_x; 
  char_map32[121] = &character_y; 
  char_map32[122] = &character_z; 
  char_map32[65] = &character_A; 
  char_map32[66] = &character_B; 
  char_map32[67] = &character_C; 
  char_map32[68] = &character_D; 
  char_map32[69] = &character_E; 
  char_map32[70] = &character_F; 
  char_map32[71] = &character_G; 
  char_map32[72] = &character_H; 
  char_map32[73] = &character_I; 
  char_map32[74] = &character_J; 
  char_map32[75] = &character_K; 
  char_map32[76] = &character_L; 
  char_map32[77] = &character_M; 
  char_map32[78] = &character_N; 
  char_map32[79] = &character_O; 
  char_map32[80] = &character_P; 
  char_map32[81] = &character_Q; 
  char_map32[82] = &character_R; 
  char_map32[83] = &character_S; 
  char_map32[84] = &character_T; 
  char_map32[85] = &character_U; 
  char_map32[86] = &character_V; 
  char_map32[87] = &character_W; 
  char_map32[88] = &character_X; 
  char_map32[89] = &character_Y; 
  char_map32[90] = &character_Z; 
  char_map32[33] = &character_exclam; 
  char_map32[64] = &character_at; 
  char_map32[35] = &character_numbersign; 
  char_map32[36] = &character_dollar; 
  char_map32[37] = &character_percent; 
  char_map32[94] = &character_asciicircum; 
  char_map32[38] = &character_ampersand; 
  char_map32[42] = &character_asterisk; 
  char_map32[40] = &character_parenleft; 
  char_map32[41] = &character_parenright; 
  char_map32[45] = &character_hyphen; 
  char_map32[95] = &character_underscore; 
  char_map32[61] = &character_equal; 
  char_map32[43] = &character_plus; 
  char_map32[58] = &character_colon; 
  char_map32[60] = &character_less; 
  char_map32[62] = &character_greater; 
  char_map32[44] = &character_comma; 
  char_map32[46] = &character_period; 
  char_map32[63] = &character_question; 
  char_map32[47] = &character_slash; 
  char_map32[34] = &character_quotedbl; 
  char_map32[125] = &character_braceright; 
  char_map32[123] = &character_braceleft; 
  char_map32[92] = &character_backslash; 
  char_map32[124] = &character_bar; 
  char_map32[126] = &character_asciitilde; 
  char_map32[96] = &character_grave; 
  #endif
}
