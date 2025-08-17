#include <std_include.hpp>

#include "ops_team.hpp"

namespace database::ops_team {
class table final : public table_interface {
public:
    void create(database_t &database) override {
        database.run_query("mgstpp.ops_team.create");
    }
};
} // namespace database::ops_team

REGISTER_TABLE(database::ops_team::table, -1)