#include "unit-tests.h"
#include "cassebrique.h"

#define _TEST_CONF_FILE "./_casstest.conf"

FILE *_f;

void initTestConf() {
  _f = fopen(_TEST_CONF_FILE, "w+");
}

void finishTestConf() {
  fclose(_f);
  remove(_TEST_CONF_FILE);
}

Test(config_funcs, init_config_returns_a_config_struct_with_right_values, .init=initTestConf, .fini=finishTestConf) {
  t_config *_c;

  fprintf(_f, "bomb_max_range=0\nbomb_up_rate=1\nbomb_down_rate=2\nyellow_flame_rate=3\nblue_flame_rate=4\nred_flame_rate=10\npass_bomb_rate=1000\nbomb_kick_rate=12345\ninvincibility_rate=3\nheart_rate=12\nhealth_up_rate=4\n");
  rewind(_f);

  _c = init_config(_TEST_CONF_FILE);

  cr_assert_neq(_c, NULL);

  cr_assert_eq(_c->bomb_max_range, 0);
  cr_assert_eq(_c->bomb_up_rate, 1);
  cr_assert_eq(_c->bomb_down_rate, 2);
  cr_assert_eq(_c->yellow_flame_rate, 3);
  cr_assert_eq(_c->blue_flame_rate, 4);
  cr_assert_eq(_c->red_flame_rate, 10);
  cr_assert_eq(_c->pass_bomb_rate, 1000);
  cr_assert_eq(_c->bomb_kick_rate, 12345);
  cr_assert_eq(_c->invincibility_rate, 3);
  cr_assert_eq(_c->heart_rate, 12);
  cr_assert_eq(_c->health_up_rate, 4);

}

Test(config_funcs, init_config_sets_values_defined_in_conf_and_sets_default_values_for_the_rest, .init=initTestConf, .fini=finishTestConf) {
  t_config *_c;

  fprintf(_f, "blue_flame_rate=4\n");
  rewind(_f);

  _c = init_config(_TEST_CONF_FILE);

  cr_assert_neq(_c, NULL);

  cr_assert_eq(_c->blue_flame_rate, 4);
  cr_assert_eq(_c->red_flame_rate, 0);

}

