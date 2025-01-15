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
  #ifndef JETBRAINS16_MONO_SET
  #define JETBRAINS16_MONO_SET
  SPACE_PX = 4;
  display_text = display_text16;

  char_map16[48] = &character_zero; 
  char_map16[49] = &character_one; 
  char_map16[50] = &character_two; 
  char_map16[51] = &character_three; 
  char_map16[52] = &character_four; 
  char_map16[53] = &character_five; 
  char_map16[54] = &character_six; 
  char_map16[55] = &character_seven; 
  char_map16[56] = &character_eight; 
  char_map16[57] = &character_nine; 
  char_map16[97] = &character_a; 
  char_map16[98] = &character_b; 
  char_map16[99] = &character_c; 
  char_map16[100] = &character_d; 
  char_map16[101] = &character_e; 
  char_map16[102] = &character_f; 
  char_map16[103] = &character_g; 
  char_map16[104] = &character_h; 
  char_map16[105] = &character_i; 
  char_map16[106] = &character_j; 
  char_map16[107] = &character_k; 
  char_map16[108] = &character_l; 
  char_map16[109] = &character_m; 
  char_map16[110] = &character_n; 
  char_map16[111] = &character_o; 
  char_map16[112] = &character_p; 
  char_map16[113] = &character_q; 
  char_map16[114] = &character_r; 
  char_map16[115] = &character_s; 
  char_map16[116] = &character_t; 
  char_map16[117] = &character_u; 
  char_map16[118] = &character_v; 
  char_map16[119] = &character_w; 
  char_map16[120] = &character_x; 
  char_map16[121] = &character_y; 
  char_map16[122] = &character_z; 
  char_map16[65] = &character_A; 
  char_map16[66] = &character_B; 
  char_map16[67] = &character_C; 
  char_map16[68] = &character_D; 
  char_map16[69] = &character_E; 
  char_map16[70] = &character_F; 
  char_map16[71] = &character_G; 
  char_map16[72] = &character_H; 
  char_map16[73] = &character_I; 
  char_map16[74] = &character_J; 
  char_map16[75] = &character_K; 
  char_map16[76] = &character_L; 
  char_map16[77] = &character_M; 
  char_map16[78] = &character_N; 
  char_map16[79] = &character_O; 
  char_map16[80] = &character_P; 
  char_map16[81] = &character_Q; 
  char_map16[82] = &character_R; 
  char_map16[83] = &character_S; 
  char_map16[84] = &character_T; 
  char_map16[85] = &character_U; 
  char_map16[86] = &character_V; 
  char_map16[87] = &character_W; 
  char_map16[88] = &character_X; 
  char_map16[89] = &character_Y; 
  char_map16[90] = &character_Z; 
  char_map16[33] = &character_exclam; 
  char_map16[64] = &character_at; 
  char_map16[35] = &character_numbersign; 
  char_map16[36] = &character_dollar; 
  char_map16[37] = &character_percent; 
  char_map16[94] = &character_asciicircum; 
  char_map16[38] = &character_ampersand; 
  char_map16[42] = &character_asterisk; 
  char_map16[40] = &character_parenleft; 
  char_map16[41] = &character_parenright; 
  char_map16[45] = &character_hyphen; 
  char_map16[95] = &character_underscore; 
  char_map16[61] = &character_equal; 
  char_map16[43] = &character_plus; 
  char_map16[58] = &character_colon; 
  char_map16[60] = &character_less; 
  char_map16[62] = &character_greater; 
  char_map16[44] = &character_comma; 
  char_map16[46] = &character_period; 
  char_map16[63] = &character_question; 
  char_map16[47] = &character_slash; 
  char_map16[34] = &character_quotedbl; 
  char_map16[125] = &character_braceright; 
  char_map16[123] = &character_braceleft; 
  char_map16[92] = &character_backslash; 
  char_map16[124] = &character_bar; 
  char_map16[126] = &character_asciitilde; 
  char_map16[96] = &character_grave; 
  #endif
}

