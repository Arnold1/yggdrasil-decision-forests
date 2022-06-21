#include "mylib.hh"

#include <iostream>
#include <chrono>
#include "absl/flags/flag.h"
#include "yggdrasil_decision_forests/dataset/data_spec.h"
#include "yggdrasil_decision_forests/dataset/data_spec.pb.h"
#include "yggdrasil_decision_forests/dataset/data_spec_inference.h"
#include "yggdrasil_decision_forests/dataset/vertical_dataset_io.h"
#include "yggdrasil_decision_forests/learner/learner_library.h"
#include "yggdrasil_decision_forests/metric/metric.h"
#include "yggdrasil_decision_forests/metric/report.h"
#include "yggdrasil_decision_forests/model/model_library.h"
#include "yggdrasil_decision_forests/utils/filesystem.h"
#include "yggdrasil_decision_forests/utils/logging.h"
#include "yggdrasil_decision_forests/serving/decision_forest/decision_forest.h"

namespace ygg = yggdrasil_decision_forests;

void cxxFoo::Bar(void){
  std::cout<<this->a<<std::endl;

  // Enable the logging. Optional in most cases.
  //InitLogging("NULL", NULL, "NULL", true);

  // Import the model.
  LOG(INFO) << "Import the model";
  const std::string model_path = "/tmp/my_saved_model/1/assets";
  std::unique_ptr<ygg::model::AbstractModel> model;
  QCHECK_OK(ygg::model::LoadModel(model_path, &model));

  // Show information about the model.
  // Like :show_model, but without the list of compatible engines.
  std::string model_description;
  model->AppendDescriptionAndStatistics(/*full_definition=*/false,
                                        &model_description);
  LOG(INFO) << "Model:\n" << model_description;

  auto start = std::chrono::high_resolution_clock::now();

  // Compile the model for fast inference.
  const std::unique_ptr<ygg::serving::FastEngine> serving_engine =
      model->BuildFastEngine().value();
  const auto& features = serving_engine->features();

  //auto start = std::chrono::high_resolution_clock::now();

  // Handle to two features.
  const auto age_feature = features.GetNumericalFeatureId("age").value();
  const auto sex_feature =
      features.GetCategoricalFeatureId("sex").value();

  // Allocate a batch of 1 examples.
  std::unique_ptr<ygg::serving::AbstractExampleSet> examples =
      serving_engine->AllocateExamples(1);

  // Set all the values as missing. This is only necessary if you don't set all
  // the feature values manually e.g. SetNumerical.
  //examples->FillMissing(features);

  // Set the value of "age" and "eduction" for the first example.
  examples->SetNumerical(/*example_idx=*/0, age_feature, 50.f, features);
  examples->SetCategorical(/*example_idx=*/0, sex_feature, "Male",
                           features);

  // Run the predictions on the first two examples.
  std::vector<float> batch_of_predictions;
  serving_engine->Predict(*examples, 1, &batch_of_predictions);

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  // To get the value of duration use the count()
  // member function on the duration object
  LOG(INFO) << "duration: " << duration.count();

  LOG(INFO) << "Predictions:";

  for (const float prediction : batch_of_predictions) {
    LOG(INFO) << "\t" << prediction;
  }

  //std::cout << "hello world" << std::endl;
}
