//
// Created by aiger on 04.05.2020.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FunctionPart {
public:
    FunctionPart(const char& oper_operation, const double& oper_value) {
        operation = oper_operation;
        value = oper_value;
    }

    double Apply(double& apply_value) const {
        if (operation == '+')
            apply_value += value;
        else
            apply_value -= value;
        return apply_value;
    }

    void Invert() {
        if (operation == '+')
            operation = '-';
        else
            operation = '+';
    }

private:
    double value;
    char operation;
};

class Function {
public:
    void AddPart(const char& operation, const double& oper_value) {
        parts.push_back(FunctionPart(operation, oper_value));
    }
    void Invert() {
        for (auto& part: parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }

    double Apply(const double& value) const {
        double ret_value = value;
        for (const auto& part : parts) {
            part.Apply(ret_value);
        }
        return ret_value;
    }

private:
    vector<FunctionPart> parts;

};

//struct Image {
//    double quality;
//    double freshness;
//    double rating;
//};
//
//struct Params {
//    double a;
//    double b;
//    double c;
//};
//
//Function MakeWeightFunction(const Params& params,
//                            const Image& image) {
//    Function function;
//    function.AddPart('-', image.freshness * params.a + params.b);
//    function.AddPart('+', image.rating * params.c);
//    return function;
//}
//
//double ComputeImageWeight(const Params& params, const Image& image) {
//    Function function = MakeWeightFunction(params, image);
//    return function.Apply(image.quality);
//}
//
//double ComputeQualityByWeight(const Params& params,
//                              const Image& image,
//                              double weight) {
//    Function function = MakeWeightFunction(params, image);
//    function.Invert();
//    return function.Apply(weight);
//}
//
//int main() {
//    Image image = {10, 2, 6};
//    Params params = {4, 2, 6};
//    cout << ComputeImageWeight(params, image) << endl;
//    cout << ComputeQualityByWeight(params, image, 46) << endl;
//    return 0;
//}
//int main() {
//    Function func;
//    double init_value = 3;
//    func.AddPart('+', 1);
//    func.AddPart('+', 33);
//    cout << func.Apply(init_value) << endl;
//    func.Invert();
//    cout << func.Apply(init_value);
//    return 0;
//}
