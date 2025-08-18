#include <std_include.hpp>

#include "combat_ops.hpp"

namespace database::combat_ops {

namespace impl {
template <database_type_t Type> std::vector<combat_ops> get_ops() {
    return database::access<std::vector<combat_ops>>(
        [&](database_t &db) -> std::vector<combat_ops> {
            auto results = db.get_database<Type>()->operator()(
                sqlpp::select(sqlpp::all_of(combat_ops::table))
                    .from(combat_ops::table)
                    .unconditionally());

            std::vector<combat_ops> list;

            for (const auto &row : results) {
                list.emplace_back(row);
            }

            return list;
        });
}
} // namespace impl

class table final : public table_interface {
public:
    void create(database_t &database) override {
        database.run_query("mgstpp.combat_ops.create");
    }
};

GET_FIELD_C(combat_ops, std::uint64_t, mission_id);
GET_FIELD_C(combat_ops, std::uint32_t, armored_max);
GET_FIELD_C(combat_ops, std::uint32_t, armored_min);
GET_FIELD_C(combat_ops, std::uint32_t, battle_gear);
GET_FIELD_C(combat_ops, std::uint32_t, car_max);
GET_FIELD_C(combat_ops, std::uint32_t, car_min);
GET_FIELD_C(combat_ops, std::uint32_t, category);
GET_FIELD_C(combat_ops, std::uint32_t, combat_count);
GET_FIELD_C(combat_ops, std::uint32_t, combat_rank);
GET_FIELD_C(combat_ops, std::uint32_t, dead_rate);
GET_FIELD_C(combat_ops, bool, is_campaign);
GET_FIELD_C(combat_ops, std::int32_t, latitude);
GET_FIELD_C(combat_ops, std::int32_t, longitude);
GET_FIELD_C(combat_ops, std::uint32_t, max_dead_rate);
GET_FIELD_C(combat_ops, std::uint32_t, min_dead_rate);
GET_FIELD_C(combat_ops, std::uint32_t, max_win_rate);
GET_FIELD_C(combat_ops, std::uint32_t, min_win_rate);
GET_FIELD_C(combat_ops, std::uint32_t, name_key);
GET_FIELD_C(combat_ops, std::string, primary_reward);
GET_FIELD_C(combat_ops, std::uint32_t, reward);
GET_FIELD_C(combat_ops, std::uint32_t, section);
GET_FIELD_C(combat_ops, std::uint32_t, section_count);
GET_FIELD_C(combat_ops, std::uint32_t, section_rank);
GET_FIELD_C(combat_ops, std::uint32_t, seed);
GET_FIELD_C(combat_ops, std::uint32_t, server_text_id);
GET_FIELD_C(combat_ops, std::uint32_t, tank_max);
GET_FIELD_C(combat_ops, std::uint32_t, tank_min);
GET_FIELD_C(combat_ops, std::uint64_t, team);
GET_FIELD_C(combat_ops, std::uint32_t, time);
GET_FIELD_C(combat_ops, std::uint32_t, time_random);
GET_FIELD_C(combat_ops, std::uint32_t, truck_max);
GET_FIELD_C(combat_ops, std::uint32_t, truck_min);
GET_FIELD_C(combat_ops, std::uint32_t, walker_gear_max);
GET_FIELD_C(combat_ops, std::uint32_t, walker_gear_min);
GET_FIELD_C(combat_ops, std::uint32_t, win_rate);

std::vector<combat_ops> get_ops() { RUN_IMPL(impl::get_ops) }
} // namespace database::combat_ops

REGISTER_TABLE(database::combat_ops::table, -1)