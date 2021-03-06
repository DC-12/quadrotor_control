#ifndef _PEGASUS_HH_
#define _PEGASUS_HH_

#include <rl_common/core.hh>


class Pegasus: public Agent {
public:
  /** Standard constructor
      \param numinputs The number of possible inputs
      \param numoutputs The number of possible outputs
  */
  Pegasus();

  virtual ~Pegasus() {}

  virtual std::vector<float> first_action(const std::vector<float> &s);
  virtual std::vector<float> next_action(float r, const std::vector<float> &s);
  virtual void last_action(float r);

  int init_policy();
  void update_policy();
  std::vector<float> get_action(const std::vector<float> &s);

protected:

private:
  int n_policy, n_state, n_action;
  float policy_stepsize, // The stepsize to update to the new policy
        policy_change, // The epsilon to move to numerically find gradient
        discount_factor;

  int parameter, max_parameter;
  std::string policy_file_name;
  float best_value, value;
  float left_value, right_value;
  bool left_done, right_done;
  std::map<std::vector<float>, float> policy_values;
  std::vector<float> policy, old_policy, new_policy;
};

#endif
