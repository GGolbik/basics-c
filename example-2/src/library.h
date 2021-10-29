/**
 * @brief This construct is inspired by https://stackoverflow.com/a/28535585
 */
#pragma once

struct library
{
  /**
   * @brief value hint
   * 
   */
  const int some_value;
  /**
   * @brief Method 1 hint
   * 
   */
  void (*method1)(void);
  /**
   * @brief Method 2 hint
   * 
   * @param arg test param
   */
  void (*method2)(int arg);
};

extern const struct library Library;