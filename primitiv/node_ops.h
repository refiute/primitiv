#ifndef PRIMITIV_NODE_OPS_H_
#define PRIMITIV_NODE_OPS_H_

#include <vector>

namespace primitiv {

class Device;
class Graph;
class Node;
class Parameter;

Node operator+(const Node &x);
Node operator-(const Node &x);
Node operator+(const Node &x, float k);
Node operator+(float k, const Node &x);
Node operator+(const Node &a, const Node &b);
Node operator-(const Node &x, float k);
Node operator-(float k, const Node &x);
Node operator-(const Node &a, const Node &b);
Node operator*(const Node &x, float k);
Node operator*(float k, const Node &x);
Node operator*(const Node &a, const Node &b);
Node operator/(const Node &x, float k);
Node operator/(float k, const Node &x);
Node operator/(const Node &a, const Node &b);

namespace node_ops {

Node input(const Shape &shape, const std::vector<float> &data, Device *dev, Graph *g);
Node input(Parameter *param, Graph *g);
Node copy(const Node &x, Device *dev);
Node pick(const Node &x, unsigned dim, const std::vector<unsigned> &ids);
Node slice(const Node &x, unsigned dim, unsigned lower, unsigned upper);
Node transpose(const Node &x);
Node dot(const Node &a, const Node &b);
Node exp(const Node &x);
Node tanh(const Node &x);
Node sigmoid(const Node &x);
Node relu(const Node &x);
Node sum(const Node &x, unsigned dim);
Node logsumexp(const Node &x, unsigned dim);
Node log_softmax(const Node &x, unsigned dim);
Node softmax(const Node &x, unsigned dim);
Node broadcast(const Node &x, unsigned dim, unsigned size);
Node softmax_cross_entropy(const Node &x, const Node &t, unsigned dim);
Node softmax_cross_entropy(const Node &x, unsigned dim, const std::vector<unsigned> &ids);
Node dropout(const Node &x, float rate, bool enabled);

namespace batch {
Node sum(const Node &x);
}  // namespace batch

namespace random {
Node bernoulli(const Shape &shape, float p, Device *dev, Graph *g);
Node uniform(const Shape &shape, float lower, float upper, Device *dev, Graph *g);
Node normal(const Shape &shape, float mean, float sd, Device *dev, Graph *g);
Node log_normal(const Shape &shape, float mean, float sd, Device *dev, Graph *g);
} // namespace random

}  // namespace node_ops
}  // namespace primitiv

#endif  // PRIMITIV_NODE_OPS_H_
