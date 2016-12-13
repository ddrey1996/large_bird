#ifndef LARGE_BIRDAPP_H
#define LARGE_BIRDAPP_H

#include "MooseApp.h"

class LargeBirdApp;

template<>
InputParameters validParams<LargeBirdApp>();

class LargeBirdApp : public MooseApp
{
public:
  LargeBirdApp(InputParameters parameters);
  virtual ~LargeBirdApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LARGE_BIRDAPP_H */
